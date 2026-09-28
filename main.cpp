#include <iostream>
#include <string>

// all the included files
#include "OperatorConsole.h"
#include "ResponseCoordinator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include "IAccessControl.h"
#include "AccessControlAdapter.h"
#include "LegacyAccessControlSystem.h"
#include "AreaGroup.h"
#include "Zone.h"
#include "Incident.h"
#include "AlertService.h"
#include "EmergencyResponseFacade.h"

int main()
{
    std::cout << "CampusGuard: Emergency Response Coordination" << std::endl;

    // 1. Build the subsystems-------------------------------------------------------

    OperatorConsole console;

    ResponseCoordinator coordinator;
    SecurityTeam security("Campus Security");
    MedicalTeam medical("Medical Response");
    FacilitiesTeam facilities("Facilities Crew");

    coordinator.registerComponent(&security);
    coordinator.registerComponent(&medical);
    coordinator.registerComponent(&facilities);

    AlertService alertService;

    IAccessControl *accessControl =
        new AccessControlAdapter(new LegacyAccessControlSystem());

    // 2. Composite building -----------------------------------------------------------

    // 2.1 EBIT Faculty
    AreaGroup ebitFaculty("EBIT Faculty");

    Zone facultyHROffice("Faculty HR Office", "EBIT-HR", accessControl);
    ebitFaculty.add(&facultyHROffice);

    // Department of Computer Science
    AreaGroup compSciDept("Department of Computer Science");
    Zone csLectureHall("Lecture Hall A (COS 132 class)", "CS-LEC-A", accessControl);
    Zone csComputerLab("Computer Lab", "CS-CLAB", accessControl);
    Zone csServerRoom("Server Room", "CS-SRV", accessControl);
    compSciDept.add(&csLectureHall);
    compSciDept.add(&csComputerLab);
    compSciDept.add(&csServerRoom);

    // Department of Information Science
    AreaGroup infoSciDept("Department of Information Science");
    Zone isLectureHall("Lecture Hall B (INF 164 class)", "IS-LEC-B", accessControl);
    Zone isDataLab("Data Lab", "IS-DATA", accessControl);
    Zone isMultimedia("Multimedia Studio", "IS-MEDIA", accessControl);
    infoSciDept.add(&isLectureHall);
    infoSciDept.add(&isDataLab);
    infoSciDept.add(&isMultimedia);

    // Attach both departments to the faculty
    ebitFaculty.add(&compSciDept);
    ebitFaculty.add(&infoSciDept);

    // 2.2 Central Library , should be attached to the institution composite

    AreaGroup library("Central Library");

    // Upper Floor Section (contains three zones) ---
    AreaGroup upperFloorSection("Upper Floor Section");
    Zone upperReadingZone("Upper Floor Reading Zone", "LIB-UP-RD", accessControl);
    Zone upperSilentStudyZone("Upper Floor Silent Study Zone", "LIB-UP-SIL", accessControl);
    Zone upperGroupStudyZone("Upper Floor Group Study Zone", "LIB-UP-GRP", accessControl);
    upperFloorSection.add(&upperReadingZone);
    upperFloorSection.add(&upperSilentStudyZone);
    upperFloorSection.add(&upperGroupStudyZone);

    // Lower Floor Section (contains three zones) ---
    AreaGroup lowerFloorSection("Lower Floor Section");
    Zone lowerReadingZone("Lower Floor Reading Zone", "LIB-LO-RD", accessControl);
    Zone commonStudyArea("Common Study Area", "LIB-LO-CMN", accessControl);
    Zone cubicles("Cubicles", "LIB-LO-CUB", accessControl);
    lowerFloorSection.add(&lowerReadingZone);
    lowerFloorSection.add(&commonStudyArea);
    lowerFloorSection.add(&cubicles);

    // Attach both sections to the library
    library.add(&upperFloorSection);
    library.add(&lowerFloorSection);

    // 3 Institution-----------------------------------------------------------------------------

    AreaGroup institution("University of Pretoria");
    institution.add(&ebitFaculty);
    institution.add(&library);

    // 4 Build the facade (aggregates the subsystems; owns none)--------------------------------

    EmergencyResponseFacade facade(&console, &coordinator, &alertService);

    // 5 Scenarios.------------------------------------------------------------------------------

    // 5.1 Scenario 1 medical emergency during a lecture in the computer science department.
    //  SCENARIO 1 - Medical emergency during the COS 132 lecture
    //    Reported -> Dispatched -> Active -> Resolved.
    //    Locks the whole Department of Computer Science
    //    Primary unit: Medical. Mediator pulls in Facilities.

    std::cout << "\n\nSCENARIO 1: Medical emergency during the COS 132 lecture "
                 "(Department of Computer Science) \n"
              << std::endl;

    // create a medical incident
    Incident medicalIncident(
        "INC-001",
        "Student collapsed during COS 132 lecture in Lecture Hall A",
        &compSciDept,
        &coordinator); // NB default state for the a created incident is reported

    std::cout << "\n[Main] Incident " << medicalIncident.getId()          // incident number basically
              << " created. Status = " << medicalIncident.getStatusName() // state status.
              << std::endl;

    facade.declareEmergency(&medicalIncident, &compSciDept, &medical);

    std::cout << "\n[Main] After declareEmergency. Status = "
              << medicalIncident.getStatusName() << std::endl;

    facade.resolveEmergency(&medicalIncident);

    std::cout << "[Main] After resolveEmergency. Status = "
              << medicalIncident.getStatusName() << std::endl;

    std::cout << "\n[Main] Command history so far:\n";
    console.printHistory();

    // 5.2 electricity outage incident
    //  SCENARIO 2 - Electricity outage at the Central Library
    //    Reported -> Dispatched -> Active -> Resolved.
    //    Locks the whole library (both floor sections, 6 zones) for evacuation.
    //    Primary unit: Facilities. Mediator pulls in Security and Medical.
    //    Once resolved, the library is unlocked so students can return.

    std::cout << "\n\nSCENARIO 2: Electricity outage at the Library"
              << std::endl;

    Incident powerIncident(
        "INC-002",
        "Electricity outage - Central Library must be evacuated",
        &library,
        &coordinator);

    std::cout << "\n[Main Incident] Incident " << powerIncident.getId()
              << " created, Status = " << powerIncident.getStatusName()
              << std::endl;

    facade.declareEmergency(&powerIncident, &library, &facilities);

    std::cout << "\n[Main Incident] After declareEmergency. Status = "
              << powerIncident.getStatusName() << std::endl;
    std::cout << "[Main Incident] Library is now locked for evacuation."
              << std::endl;

    // Power restored, incident resolved, then library unlocked for return.
    std::cout << "\n[Main Incident] Power restored - resolving incident and "
                 "unlocking the library."
              << std::endl;

    facade.resolveEmergency(&powerIncident);

    library.unlock();

    std::cout << "[Main Incident] After resolveEmergency and unlock. Status = "
              << powerIncident.getStatusName() << std::endl;

    std::cout << "\n[Main Incident] Command history after power outage scenario:\n";
    console.printHistory();

    // SCENARIO 3 - Natural disaster: campus-wide lockdown
    //   One lock() on the institution cascades through the EBIT faculty,
    //   both departments, and both library sections.

    std::cout << "\n\nSCENARIO 3: Natural disaster - campus-wide lockdown"
              << std::endl;

    Incident disasterIncident(
        "INC-003",
        "Tornado warning - full campus lockdown",
        &institution,
        &coordinator);

    std::cout << "\n[Main Incident] Incident " << disasterIncident.getId()
              << " created. Status = " << disasterIncident.getStatusName()
              << std::endl;

    facade.declareEmergency(&disasterIncident, &institution, &security);

    std::cout << "\n[Main Incident] Deploying Medical and Facilities as backup:"
              << std::endl;

    facade.declareEmergency(&disasterIncident, &institution, &medical);
    facade.declareEmergency(&disasterIncident, &institution, &facilities);

    std::cout << "\n[Main Incident] After full deployment. Status = "
              << disasterIncident.getStatusName() << std::endl;

    facade.resolveEmergency(&disasterIncident);

    std::cout << "[Main Incident] After resolveEmergency. Status = "
              << disasterIncident.getStatusName() << std::endl;

    std::cout << "\n[Main Incident] Full command history:\n";
    console.printHistory();

    // 4.checkpoints.-------------------------------------------------------------------

    std::cout << "\n\nCross-pattern checkpoints" << std::endl;

    std::cout
        << "Composite : institution.isLocked()          = "
        << (institution.isLocked() ? "true" : "false") << "\n"
        << "Composite : ebitFaculty.isLocked()          = "
        << (ebitFaculty.isLocked() ? "true" : "false") << "\n"
        << "Composite : facultyHROffice.isLocked()      = "
        << (facultyHROffice.isLocked() ? "true" : "false") << "\n"
        << "Composite : compSciDept.isLocked()          = "
        << (compSciDept.isLocked() ? "true" : "false") << "\n"
        << "Composite : csLectureHall.isLocked()        = "
        << (csLectureHall.isLocked() ? "true" : "false") << "\n"
        << "Composite : csComputerLab.isLocked()        = "
        << (csComputerLab.isLocked() ? "true" : "false") << "\n"
        << "Composite : csServerRoom.isLocked()         = "
        << (csServerRoom.isLocked() ? "true" : "false") << "\n";

    std::cout
        << "Composite : infoSciDept.isLocked()          = "
        << (infoSciDept.isLocked() ? "true" : "false") << "\n"
        << "Composite : isLectureHall.isLocked()        = "
        << (isLectureHall.isLocked() ? "true" : "false") << "\n"
        << "Composite : isDataLab.isLocked()            = "
        << (isDataLab.isLocked() ? "true" : "false") << "\n"
        << "Composite : isMultimedia.isLocked()         = "
        << (isMultimedia.isLocked() ? "true" : "false") << "\n";

    std::cout
        << "Composite : library.isLocked()              = "
        << (library.isLocked() ? "true" : "false") << "\n"
        << "Composite : upperFloorSection.isLocked()    = "
        << (upperFloorSection.isLocked() ? "true" : "false") << "\n"
        << "Composite : lowerFloorSection.isLocked()    = "
        << (lowerFloorSection.isLocked() ? "true" : "false") << "\n"
        << "Composite : upperReadingZone.isLocked()     = "
        << (upperReadingZone.isLocked() ? "true" : "false") << "\n"
        << "Composite : upperSilentStudyZone.isLocked() = "
        << (upperSilentStudyZone.isLocked() ? "true" : "false") << "\n"
        << "Composite : upperGroupStudyZone.isLocked()  = "
        << (upperGroupStudyZone.isLocked() ? "true" : "false") << "\n"
        << "Composite : lowerReadingZone.isLocked()     = "
        << (lowerReadingZone.isLocked() ? "true" : "false") << "\n"
        << "Composite : commonStudyArea.isLocked()      = "
        << (commonStudyArea.isLocked() ? "true" : "false") << "\n"
        << "Composite : cubicles.isLocked()             = "
        << (cubicles.isLocked() ? "true" : "false") << "\n";

    // 5. Shutdown-----------------------------------------------------------------------------

    delete accessControl;

    std::cout << "Shutdown complete" << std::endl;
    return 0;
}
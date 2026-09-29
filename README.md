# COS214_Practical_5
COS214 practical 5 group assignment.
# CampusGuard

**COS214 Practical 5 — Emergency Response Coordination Platform**

CampusGuard is an emergency-response coordination system for a large university
campus. It manages the full lifecycle of an incident — from the moment it is
reported until it is resolved or cancelled — by coordinating security, medical,
and facilities teams, locking and unlocking campus areas, issuing emergency
alerts, and integrating with a legacy access-control system.

The system is built around six GoF design patterns: **Command**, **Mediator**,
**Adapter**, **Facade**, **Composite**, and **State**.



### Installing Docker (Ubuntu / WSL)

```bash
sudo apt update
sudo apt install -y docker.io docker-compose-v2
sudo service docker start
sudo usermod -aG docker $USER   # then close and reopen the terminal
```

Verify:

```bash
docker info
docker compose version
```

---

## Build and Run

From the project root, run:

docker compose up --build



To clean up (stop and remove the container):


docker compose down


To force a full rebuild without cache:

docker compose build --no-cache
docker compose up




### Using the Makefile 

```bash
make clean      # remove old .o files and the binary
make            # compile every .cpp, link into ./campusguard
make run        # build if needed, then execute ./campusguard
```


### Manual Compilation

If you want to bypass the Makefile:

```bash
g++ -std=c++11 -Wall -g -o campusguard *.cpp
./campusguard
```

Or compile and link in two steps:

```bash
g++ -std=c++11 -Wall -g -c *.cpp       # produces one .o per .cpp
g++ -std=c++11 -Wall -g -o campusguard *.o
./campusguard

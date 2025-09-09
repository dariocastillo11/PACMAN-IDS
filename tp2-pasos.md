crar archivo ***horusec-config.json***
```
{
  "security": {
    "critical": true,
    "high": true,
    "medium": false,
    "low": false
  }
}
```

- configuro workflow de github actions
creo archivo en workflow llamado horusec.yml 
```
name: Horusec Security Scan

on:
  pull_request:
    branches:
      - main

jobs:
  horusec_scan:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v3

      - name: Install Horusec
        run: |
          curl -fsSL https://raw.githubusercontent.com/ZupIT/horusec/main/deployments/scripts/install.sh | bash -s latest

      - name: Run Horusec Scan
        run: |
          horusec start -p . --config-file-path=horusec-config.json

```
LO que hace es ejecutarseautomaticamenteen cada PR 




instalacon horusec local:
***https://github.com/ZupIT/horusec***
```
curl -fsSL https://raw.githubusercontent.com/ZupIT/horusec/master/deployments/scripts/install.sh | bash -s latest

```
```
horusec version
```

prueba de horusec local :
```
horusec start -p . --disable-docker
```
```
dario@dario-N-737R:/media/dario/56E247D9E247BC4D/Users/dario/OneDrive/Desktop/fcfyn/4to año/ingenieria sofware/pacman/Pacman_Complete$ 

horusec start -p . --disable-docker


time="2025-09-09T13:14:07-03:00" level=warning msg="{HORUSEC_CLI} When starting the analysis WE SKIP A TOTAL OF 831 FILES that are not considered to be analyzed. To see more details use flag --log-level=debug"

time="2025-09-09T13:14:07-03:00" level=warning msg="Horusec will return a timeout after 600 seconds. This time can be customized in the cli settings."

time="2025-09-09T13:14:07-03:00" level=warning msg="{HORUSEC_CLI} PLEASE DON'T REMOVE \".horusec\" FOLDER BEFORE THE ANALYSIS FINISH! Don’t worry, we’ll remove it after the analysis ends automatically! Project sent to folder in location: [/media/dario/56E247D9E247BC4D/Users/dario/OneDrive/Desktop/fcfyn/4to año/ingenieria sofware/pacman/Pacman_Complete/.horusec/0a183fb8-41a1-42d4-89a3-44e160ebbb46]"



==================================================================================

HORUSEC ENDED THE ANALYSIS WITH STATUS OF "success" AND WITH THE FOLLOWING RESULTS:

==================================================================================

Analysis StartedAt: 2025-09-09 13:14:07
Analysis FinishedAt: 2025-09-09 13:14:09

==================================================================================


time="2025-09-09T13:14:09-03:00" level=warning msg="{HORUSEC_CLI} No authorization token was found, your code it is not going to be sent to horusec. Please enter a token with the -a flag to configure and save your analysis"

time="2025-09-09T13:14:09-03:00" level=warning msg="YOUR ANALYSIS HAD FINISHED WITHOUT ANY VULNERABILITY!"

time="2025-09-09T13:14:09-03:00" level=warning msg="{HORUSEC_CLI} Horusec not show info vulnerabilities in this analysis, to see info vulnerabilities add option \"--information-severity=true\". For more details use (horusec start --help) command."
dario@dario-N-737R:/media/dario/56E247D9E247BC4D/Users/dario/OneDrive/Desktop/fcfyn/4to año/ingenieria sofware/pacman/Pacman_Complete$ 

time="2025-09-09T13:14:09-03:00" level=warning msg="{HORUSEC_CLI} Horusec not show info vulnerabilities in this analysis, to see info vulnerabilities add option \"--information-severity=true\". For more details use (horusec start --help) command."
```


# agrego vulnerabilidad de prueba:
## creo rama nueva "prueba-vulnerable" donde meto fallas
```
# crar archivo vulnerabilidad con contra harcdcodeada
def test_vulnerability():
    password = "123456"  # Horusec debería detectarlo como vulnerabilidad
    print(f"Contraseña: {password}")
```


```
# crar archivo vulnerable.c hace shell injection
#include <stdlib.h>

void vulnerable() {
    char command[100];
    sprintf(command, "ls %s", getenv("USER"));  // uso inseguro de sprintf
    system(command);  // Horusec puede marcar esto como HIGH
}

```
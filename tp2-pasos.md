# Trabajo Práctico  - Gestión de la Calidad de Software

**Tema:** Integración de Herramientas de Seguridad en el Ciclo de Desarrollo (DevSecOps)

## 1. Configuración de Horusec

### 1.1 Archivo de configuración (`horusec-config.json`)

```json
{
  "security": {
    "critical": true,
    "high": true,
    "medium": false,
    "low": false
  }
}
```

* Permite que Horusec bloquee el pipeline si se detectan vulnerabilidades de severidad **CRÍTICA** o **ALTA**.

---

### 1.2 Workflow de GitHub Actions (`horusec.yml`)

```yaml
name: Horusec Security Scan

on:
  pull_request:
    branches:
      - develop
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
          horusec start \
            -p . \
            --config-file-path=horusec-config.json \
            --information-severity=true \
            --enable-owasp-dependency-check \
            --enable-git-history \
            --enable-shellcheck \
            --log-level=debug \
            --return-error \
            --disable-docker \
            --output-format json \
            --json-output-file horusec-report.json
```

* Se ejecuta automáticamente en **cada Pull Request**.
* Instala Horusec en el runner y analiza el proyecto usando la configuración definida.

---

### 1.3 Instalación local de Horusec

```bash
curl -fsSL https://raw.githubusercontent.com/ZupIT/horusec/master/deployments/scripts/install.sh | bash -s latest
horusec version
```

* Permite probar Horusec **localmente** antes de subir cambios al repositorio.

---

### 1.4 Prueba local

```bash
horusec start -p . --disable-docker
```

* Detecta vulnerabilidades locales sin Docker.
* Mensaje de salida cuando no hay vulnerabilidades:

```
YOUR ANALYSIS HAD FINISHED WITHOUT ANY VULNERABILITY!
```

---

## 2. Vulnerabilidades de prueba

### 2.1 Python (`vulnerable.py`)

```python
def test_vulnerability():
    password = "123456"  # Horusec debería detectarlo como vulnerabilidad
    print(f"Contraseña: {password}")
```

* Hard-coded password → CRÍTICA.

---

### 2.2 C (`vulnerable.c`)

```c
#include <stdlib.h>

void vulnerable() {
    char command[100];
    sprintf(command, "ls %s", getenv("USER"));  // uso inseguro de sprintf
    system(command);  // Horusec puede marcar esto como HIGH
}
```

* Posible **Shell Injection** → alta severidad.

---

### 2.3 Comando para probar Horusec local con reporte

```bash
horusec start \
  -p . \
  --config-file-path=horusec-config.json \
  --information-severity=true \
  --enable-owasp-dependency-check \
  --enable-git-history \
  --enable-shellcheck \
  --log-level=debug \
  --return-error \
  --disable-docker \
  --output-format json \
  --json-output-file horusec-report.json
```

* Genera un archivo **`horusec-report.json`** con todas las vulnerabilidades detectadas.

---

## 3. Resultado del análisis (`horusec-report.json`)

**Extracto de vulnerabilidades encontradas:**

```json
{
  "version": "v2.8.0",
  "id": "91a26768-8e62-4678-92b3-0e3dcfc4383e",
  "repositoryID": "00000000-0000-0000-0000-000000000000",
  "repositoryName": "",
  "workspaceID": "00000000-0000-0000-0000-000000000000",
  "workspaceName": "",
  "status": "success",
  "errors": "",
  "createdAt": "2025-09-09T13:45:35.011218338-03:00",
  "finishedAt": "2025-09-09T13:45:37.490895643-03:00",
  "analysisVulnerabilities": [
    {
      "vulnerabilityID": "00000000-0000-0000-0000-000000000000",
      "analysisID": "91a26768-8e62-4678-92b3-0e3dcfc4383e",
      "createdAt": "2025-09-09T13:45:37.490898013-03:00",
      "vulnerabilities": {
        "vulnerabilityID": "9199cb83-e58e-4732-8f6c-05a9ac993a4e",
        "line": "3",
        "column": "4",
        "confidence": "MEDIUM",
        "file": "vulnerable.py",
        "code": "password = \"123456\"  # Horusec debería detectarlo como vulnerabilidad",
        "details": "(1/1) * Possible vulnerability detected: Hard-coded password\nThe software contains hard-coded credentials, such as a password or cryptographic key, which it uses for its own inbound authentication, outbound communication to external components, or encryption of internal data. For more information checkout the CWE-798 (https://cwe.mitre.org/data/definitions/798.html) advisory.",
        "securityTool": "HorusecEngine",
        "language": "Leaks",
        "severity": "CRITICAL",
        "type": "Vulnerability",
        "commitAuthor": "-",
        "commitEmail": "-",
        "commitHash": "-",
        "commitMessage": "-",
        "commitDate": "-",
        "rule_id": "HS-LEAKS-26",
        "vulnHash": "7bc5b447262f9066ecbecba90bea29d8d29e9f2db6776aa7aabf54cd2d12b10c",
        "deprecatedHashes": [
          "95d31ab11a6b9f5b5a0cbb85a8aefe319ee19e67d5ca85b20352ea34c5b46828",
          "1108beba805507f85b8508ef9643d8d8ffb3b47d83ff78348875f499c48ff121"
        ],
        "securityToolVersion": "",
        "securityToolInfoUri": ""
      }
    },
    {
      "vulnerabilityID": "00000000-0000-0000-0000-000000000000",
      "analysisID": "91a26768-8e62-4678-92b3-0e3dcfc4383e",
      "createdAt": "2025-09-09T13:45:37.490902393-03:00",
      "vulnerabilities": {
        "vulnerabilityID": "9d9d3fe0-1616-4180-916b-7b45c51d4a60",
        "line": "100",
        "column": "4",
        "confidence": "MEDIUM",
        "file": "tp2-pasos.md",
        "code": "password = \"123456\"  # Horusec debería detectarlo como vulnerabilidad",
        "details": "(1/1) * Possible vulnerability detected: Hard-coded password\nThe software contains hard-coded credentials, such as a password or cryptographic key, which it uses for its own inbound authentication, outbound communication to external components, or encryption of internal data. For more information checkout the CWE-798 (https://cwe.mitre.org/data/definitions/798.html) advisory.",
        "securityTool": "HorusecEngine",
        "language": "Leaks",
        "severity": "CRITICAL",
        "type": "Vulnerability",
        "commitAuthor": "-",
        "commitEmail": "-",
        "commitHash": "-",
        "commitMessage": "-",
        "commitDate": "-",
        "rule_id": "HS-LEAKS-26",
        "vulnHash": "ee31e28d824202bd1963f059876953175776fe79b8efcd4da0c61326e55c5b1c",
        "deprecatedHashes": [
          "2587002fdf73b31fc3d3e51724083e9a46ca45249b7fe18dc502db57b68e05f6",
          "394ebc7f3b21c8516ade8695c96e07fe18300ab2f04a4178b10f49feb72612cf"
        ],
        "securityToolVersion": "",
        "securityToolInfoUri": ""
      }
    }
  ]
}
```

* Horusec bloquea la ejecución del pipeline debido a vulnerabilidades **CRÍTICAS**.
* El análisis incluye **archivo, línea, código, severidad y descripción** de la vulnerabilidad.

---

## 4. Conclusión

* Se logró integrar Horusec en el **pipeline de CI/CD**.
* Se verificó que:

  * Pull Requests con vulnerabilidades críticas o altas son **bloqueadas**.
  * Pull Requests sin vulnerabilidades continúan normalmente.
* Se probó **localmente** y se generó un **archivo JSON de reporte** que documenta todas las vulnerabilidades detectadas.
* La integración permite asegurar la **calidad y seguridad del software** de manera automatizada.

---


# correr horusec con docker

```
sudo docker run --rm -v $(pwd):/src horuszup/horusec-cli:latest horusec start \
    --project-path /src \
    --output-format json \
    --json-output-file /src/horusec-report.json \
    --disable-docker
```
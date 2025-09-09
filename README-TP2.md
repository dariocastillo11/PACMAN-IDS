
---

# 📋 Trabajo Práctico Grupal - Gestión de la Calidad de Software

## Tema: Integración de Herramientas de Seguridad en el Ciclo de Desarrollo (DevSecOps) 🔒

### 🎯 Objetivo General

El presente trabajo práctico tiene como objetivo principal que los estudiantes incorporen de manera práctica los principios de la **gestión de la calidad de software** dentro de un **pipeline de integración y entrega continua (CI/CD)**.

Se utilizará la herramienta de análisis estático de seguridad **Horusec**, con el fin de automatizar la detección temprana de vulnerabilidades en el código fuente. Esto permitirá entender que la calidad no solo se mide por la funcionalidad, sino también por la **robustez y resistencia ante posibles amenazas**.

---

## ✅ Criterios de Aceptación

El trabajo se considerará aprobado si se cumplen los siguientes criterios de forma exitosa:

1. **Pipeline Bloqueante** ❌

   * La ejecución del pipeline de CI/CD debe detenerse por completo si **Horusec identifica vulnerabilidades de severidad CRÍTICA o ALTA**.
   * Si no se encuentran vulnerabilidades, o solo se detectan de severidad baja o media, el pipeline debe **continuar y finalizar con éxito**.

2. **Integración Operativa** ⚙️ ✅

   * Horusec debe estar **integrado directamente en el flujo de GitHub Actions** del repositorio de la materia Ingeniería de Software.
   * La ejecución debe ser **automática ante un evento definido** (ejemplo: push a una rama, pull request).

3. **Configuración y Evidencia** 📊

   * El repositorio debe incluir un archivo de configuración **horusec-config.json** que demuestre la personalización de los criterios de análisis.
   * Se debe proporcionar **evidencia tangible** en el historial de GitHub Actions que demuestre que el pipeline se ha detenido intencionalmente al encontrar vulnerabilidades (ej.: captura de pantalla del workflow fallido).

---

## 📋 Requisitos Técnicos de Implementación

1. **Selección del Repositorio**

   * Se realizará sobre el **repositorio de GitHub del proyecto desarrollado en la materia Ingeniería de Software**.

2. **Configuración del Workflow**

   * Crear un **workflow de GitHub Actions** que incluya un **job específico para la ejecución de Horusec**.

3. **Definición de Severidad**

   * Configurar Horusec para que su **código de salida (exit code)** sea diferente de cero (0) ante hallazgos críticos o altos, cumpliendo con el criterio de bloqueo.

4. **Documentación Interna**

   * Realizar un **informe detallado** con el trabajo realizado, incluyendo configuración, pruebas y resultados.

---

## 📦 Modalidad de Entrega

* **Formato:** Grupal
* **Entregable:** URL del repositorio de GitHub
* **Plazo de entrega:** Jueves 11 de septiembre
* Adjuntar también el **informe del trabajo realizado**.

---

## 📚 Recursos de Soporte y Referencia

* **Documentación oficial de Horusec:** [https://horusec.io/docs/](https://horusec.io/docs/)
* **Documentación de GitHub Actions:** [https://docs.github.com/en/actions](https://docs.github.com/en/actions)
* **Slides y clase grabada de la materia.**

---

Si querés, puedo hacer también una **versión extendida del README** que incluya:

* Ejemplo de **workflow de GitHub Actions** listo para usar con Horusec
* Ejemplo de **horusec-config.json** configurado para bloqueos de severidad alta/critica
* Indicaciones para **probar el pipeline y generar evidencia**

Eso dejaría tu entrega prácticamente lista para enviar.



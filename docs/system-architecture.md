# System Architecture — Env-Station

## 1. Objectif général
L’objectif du système est de mesurer et de analyser différents paramètres environnementaux à l’aide d’un microcontrôleur ESP32 associé au capteur BME680, puis d’organiser les données pour une éventuelle transmission vers une interface cloud.

Le système est conçu de manière modulaire afin de permettre l’ajout ultérieur de capteurs ou de fonctionnalités.

---

## 2. Architecture matérielle

### 2.1 Composants principaux
- ESP32 DevKit V1 : microcontrôleur, communication Wi-Fi, gestion du firmware.
- BME680 : capteur de température, humidité, pression et gaz (VOC).
- Breadboard + câbles Dupont.
- Alimentation USB 5 V.

### 2.2 Interface de communication
- Le capteur BME680 communique avec l’ESP32 via le bus I²C.
- L’ESP32 peut transmettre les données :
  - via liaison série (phase de test),
  - via Wi-Fi dans une version ultérieure.

### 2.3 Répartition fonctionnelle
- Mesure : BME680
- Traitement : ESP32 (filtrage, compensation, mise en forme JSON)
- Communication : liaison série ou Wi-Fi

---

## 3. Architecture logicielle

### 3.1 Structure du firmware
- Initialisation du capteur et du bus I²C.
- Lecture périodique des valeurs.
- Vérification d’intégrité et gestion d’erreurs.
- Formatage des données sous forme structurée.
- Possibilité d’ajouter des modules (MQTT, HTTP, stockage local).

### 3.2 Cycle d’exécution
1. Initialisation des périphériques.
2. Lecture du BME680.
3. Traitement de la donnée.
4. Affichage/émission.
5. Délai avant nouvel échantillonnage.

---

## 4. Schéma fonctionnel simplifié

            +-------------+
            |   BME680    |
            |(Temp/Hum/...)|
            +------+------+
                   |
                   | I²C
                   |
            +------v------+
            |    ESP32    |
            | Acquisition |
            | Traitement  |
            +------+------+
                   |
        +----------+-----------+
        |                      |
    Liaison série        Wi-Fi (future)
        |                      |
    Console PC             Cloud/API

---

## 5. Gestion d’erreurs et limitations
- Vérification de la communication I²C.
- Gestion des cas de lecture invalide.
- Limitation actuelle : pas d’enregistrement local des données.
- Optimisation énergie non encore implémentée.

---

## 6. Évolutions prévues
- Transmission des données vers une API ou un service MQTT.
- Ajout d’un tableau de bord web pour visualisation en temps réel.
- Intégration d’un stockage local (SPIFFS ou carte SD).
- Ajout de capteurs supplémentaires (luminosité, présence, particules).
- Optimisation pour usage sur batterie.



# Calculateur de Consommation de Carburant — C++ / Qt Creator

## Présentation du projet
Ce projet est une application graphique de bureau développée en **C++** à l'aide du framework industriel **Qt Creator**. Réalisé dans le cadre de mon cursus en ingénierie informatique, ce programme applique les concepts fondamentaux de la **Programmation Orientée Objet (POO)** et de la conception d'interfaces graphiques (GUI).

L'application offre une interface intuitive permettant à l'utilisateur de saisir le kilométrage parcouru par un véhicule ainsi que la quantité de carburant consommée, afin de calculer et d'afficher automatiquement la consommation moyenne de manière normalisée en **litres pour 100 kilomètres (L/100 km)**.

---

## Architecture Logicielle & Séparation des Responsabilités
Le projet respecte les principes de modularité et de découplage en séparant strictement la logique algorithmique (Métier) de la couche d'affichage (Interface Graphique).

Le code source est structuré en trois composants principaux :

### 1. Le Cœur Métier (Algorithme POO)
*   **`Vehicule.h` & `Vehicule.cpp`** : Classe autonome représentant l'entité véhicule.
    *   **Encapsulation** : Les données sensibles (`kilometrage` et `litres`) sont protégées en accès privé (`private`).
    *   **Interface publique** : L'accès aux attributs s'effectue via des accesseurs mutateurs (*Setters*).
    *   **Rigueur mathématique** : La méthode `calculerConsommation()` intègre une sécurité algorithmique bloquant toute division par zéro (renvoyant `0` si le kilométrage est nul ou négatif).

### 2. L'Interface Graphique (Conception GUI Qt)
*   **`MainWindow.h` & `MainWindow.cpp`** : Classe pilotant la fenêtre principale de l'application. Elle assemble les briques graphiques (ou *Widgets*) fournies par la bibliothèque Qt :
    *   `QLineEdit` : Champs de saisie textuelle pour capturer les entrées.
    *   `QPushButton` : Boutons d'action pour le déclenchement du calcul et la réinitialisation de l'IHM.
    *   `QLabel` : Zones d'affichage de texte pour le titre et la restitution dynamique du résultat.
    *   `QVBoxLayout` : Gestionnaire de mise en page verticale assurant l'alignement propre des composants.

### 3. Le Point d'Entrée
*   **`main.cpp`** : Initialise l'instance principale de l'application Qt (`QApplication`), instancie la vue et maintient la boucle d'exécution événementielle ouverte.

---

## Mécanisme Clé : Signaux et Slots Qt
L'interaction dynamique entre les boutons de l'interface graphique et notre logique C++ repose entièrement sur l'architecture événementielle de Qt via le système des **Signaux et Slots** :
- Le bouton `btnCalculer` émet un signal `clicked` lors de la pression utilisateur.
- Ce signal est intercepté par la macro `connect()` qui redirige le flux d'exécution vers le slot privé `calculer()` de la classe `MainWindow`.
- De même, le bouton `btnReset` est connecté au slot `reinitialiser()` pour vider les champs instantanément.

---

## Robustesse & Gestion des Entrées Utilisateur
Afin de garantir la stabilité de l'application et d'anticiper les erreurs d'utilisation courantes, plusieurs couches de sécurité ont été intégrées :
- **Validation Typologique (`QDoubleValidator`)** : Les champs de saisie filtrent les touches du clavier en amont pour interdire l'introduction de lettres ou de caractères spéciaux, n'acceptant que les nombres décimaux.
- **Contrôle d'Intégrité Logique** : Avant de transmettre les données au modèle `Vehicule`, le slot de contrôle vérifie que le kilométrage et l'essence utilisés sont strictement supérieurs à zéro. En cas d'anomalie, l'exécution est suspendue et une alerte contextuelle de sécurité `QMessageBox::warning` est projetée à l'écran.

---

## Fonctionnalités & Concepts Clés Validés
- Programmation Orientée Objet en langage C++ (Classes, Encapsulation, Constructeurs, Méthodes `const`).
- Conception d'interfaces graphiques avec le framework Qt (Widgets, Layouts).
- Gestion des architectures événementielles (Modèle Signaux / Slots).
- Traitement de la robustesse logicielle (Validation et filtrage des flux d'entrées utilisateur).

---

## 🚀 Prérequis pour exécuter le projet localement
Pour compiler et lancer cette application sur votre machine, vous devez disposer de :
1. **Qt Creator** (Version 5 ou 6).
2. Un compilateur C++ compatible (MinGW pour Windows, GCC pour Linux ou Clang pour macOS).

### Instructions de lancement :
1. Ouvrez Qt Creator.
2. Cliquez sur *Open Project* et sélectionnez le fichier `.pro` de ce dossier.
3. Configurez le kit d'exécution, puis cliquez sur le bouton vert **Run** (ou faites `Ctrl + R`).

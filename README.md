![Compatible](https://img.shields.io/badge/Compatible-linuxX64%20macOSX64-success)
![Language](https://img.shields.io/badge/Language-c%2B%2B-blue)
![License](https://img.shields.io/badge/Licence-CC%20BY--NC--SA%204.0-brightgreen)


Miso Mania Par Romain Rochebloine, Jules Ginhac et Mathieu Ponton.
-------




-------
### Préambule
<font size="2"> 
Projet réalisé dans le cadre de L'UE LIFAP4 à l'université Claude Bernard Lyon 1, dans le cadre de notre deuxième année de cursus préparatoire
aux écoles d'ingénieur Polytech (Peip). Les cours magistraux de cette UE ont été assurés par Alexandre Meyer et Nicolas Pronost, tous deux 
chercheurs à LIRIS, un laboratoire du CNRS.
</font>

-------
## I)Prérequis Sous Linux/WSL
1. Un système d'exploitation **Linux** (*Ubuntu, Debian, Arch, etc...*), ou **WSL** (*Windows Subsystem for Linux*) sous Windows 10 ou supérieur.
2. Le compilateur **g++**. 
    Pour l'installer sous Debian ou Ubuntu: 
    ```sudo apt update && sudo apt upgrade``` 
    ```sudo apt-get install g++ ```

3. La bibliothèque graphique SDL2.
    Pour l'installer sous Debian ou Ubuntu: 
    ```sudo apt-get install libsdl2-dev```

4. La bibliothèque graphique SDL2_image.
    Pour l'installer sous Debian ou Ubuntu : 
    ```sudo apt-get install libsdl2-image-dev```

Pour installer réaliser les étapes **1 à 3** il est possible de taper la commande suivante depuis le *terminal d'une distribution Debian ou Ubuntu*:   
    ```sudo apt update && sudo apt upgrade && sudo apt-get install g++ libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev -y```

Ou depuis Arch Linux : 
    ```sudo pacman -Syu && sudo pacman -S gcc sdl2 sdl2_image sdl2_ttf sdl2_mixer```

Pour vérifier que le compilateur et SDL sont bien installés il suffit de taper la commande suivante depuis le *terminal*:
    ```g++ --version && sdl2-config --version```

Si  les versions de **g++** et **SDL2** s'affichent, c'est que tout est bien installé.

## I-bis) Prérequis Sous macOS
1. Un système d'exploitation **macOS** (*Catalina, Mojave, High Sierra, etc...*).
2. Le compilateur **g++**. 
    Pour l'installer sous macOS: 
    ```xcode-select --install```
3. Le gestionnaire de paquets **Homebrew**.
   Pour l'installer sous macOS: 
   ```/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"```
4. Les bibliothèques graphiques **SDL2**, **SDL2_image**, **SDL2_ttf**, **SDL2_mixer**.
   Pour les installer sous macOS: 
   ```brew install sdl2 sdl2_image sdl2_ttf sdl2_mixer```

## II) Téléchargement et Compilation 
1. Télécharger le projet sur GitHub.
   Ouvrir un terminal depuis le dossier où vous souhaitez télécharger le projet, puis taper la commande suivante : 
   ```git clone https://github.com/Claquettes/S4.git```
2. **Sous Linux/Wsl**, Ouvrir un terminal depuis le dossier où vous avez téléchargé le projet, puis taper la commande suivante afin de compiler le projet, et créer les exécutables: 
   ```make```   
     
Sous **MacOS**, Ouvrir un terminal depuis le dossier où vous avez téléchargé le projet, puis taper la commande suivante afin de compiler le projet, et créer les exécutables: 
   ```make -f makefile.mac ```

## III) Utilisation
1. Pour lancer le jeu, il suffit de taper la commande suivante depuis le terminal : 
   ```bin/jeu```
2. Une fenêtre s'ouvre, et le jeu se lance. Un menu s'affiche, et vous pouvez choisir de jouer, créer un niveau, ou consulter le leaderboard.

## IV) Création de niveau:
1. Une fois le mode création de niveau lancé, il suffit de cliquer sur les cases pour les remplir du bloc selectionné. Pour changer de bloc, il suffit d'appuyer sur la toucne avec le numéro du bloc.
2. Liste des blocs: 
    - **1**: Caisse de base, de taille 1x1.
    - **2**: Caisse de taille 2x2.
    - **3**: Petite Plateforme, de taille 3x1.
    - **4**: Plateforme, de taille 5x1.
    - **5**: Grande Plateforme, de taille 7x1.
    - **6**: Orbe de double saut.
    - **7**: Box de fin de niveau.
    - **8**: Arbre (sans collision).
    - **9**: Pic.(tue le joueur au contact)
    - **0**: Ressort.
3. La sauvegarde du niveau se fait automatiquement à chaque modification. Pour revenir au menu principal, il suffit d'appuyer sur la touche **Echap**. Le niveau sera alors sauvegardé dans le dossier **levels**, dans le fichier **level0.json**.

## V) Documentation 
1.  La Documentation du projet à été générée à l'aide de Doxygen. Afin de pouvoir la consulter, il faut d'abbord l'installer. Pour l'installer : 
    ```sudo apt-get install doxygen```
2. Pour générer la documentation, il suffit de taper la commande suivante depuis le terminal : 
    ``` doxygen doc/image.doxy```
3. Pour consulter la documentation, il suffit de taper la commande suivante depuis le terminal : 
    ```[Your_WebBrowser] doc/html/index.html```
    En remplaçant **Your_WebBrowser** par le navigateur de votre choix.

## VI) Organisation de l'archive
1. **src**: Contient les fichiers sources du projet.
2. **data**: Contient les assets et les polices du projet.
    - **assets**: Contient les images du projet.
    - **font**: Contient les polices du projet.   
3. **doc**: Contient la documentation du projet, le diagramme des classes, notre présantation orale, ainsi que le diagramme de Gantt.
4. **bin**: Contient les exécutables du projet, le dossier et son contenu sont générés lors de la compilation.
5. **obj**: Contient les fichiers objets du projet, le dossier et son contenu sont générés lors de la compilation.
6. **niveaux**: Contient les niveaux du projet, ainsi que ceux créés ou importés par l'utilisateur.
7. **times**: Contient les fichiers de sauvegarde des temps des joueurs.
8. **user** : Contient les fichiers propres à l'utilisateur, comme les icones ou les coins le dossier et son contenu sont générés lors de la compilation.
9. **makefile**: Fichier permettant de compiler le projet sous Linux/WSL.
10. **makefile.mac**: Fichier permettant de compiler le projet sous macOS.
11. **README.md**: Fichier contenant les informations relatives au projet.
12. **LICENSE**: Fichier contenant la licence du projet.
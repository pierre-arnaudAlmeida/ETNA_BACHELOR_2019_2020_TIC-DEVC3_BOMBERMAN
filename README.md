# Groupe de salija_e

```
ALMEIDA Pierre-Arnaud
LEZIO Guyshaman
SALIJAJ Ernis
```

## Installer une interface graphique sur une VM en ligne de commande
> Pour notre projet il nous faut pouvoir tester notre application 'bomberman' d'un point de vue graphique.
> Pour cela il nous faut installer une interface graphique (desktop) sur notre VM.
> Nous devons donc taper succéssivement les différentes commandes : 

```bash
    sudo apt-get update
    sudo apt-get install xfce4
```

> A la fin de l'installation il nous faut redemarrer la VM, que l'on peut lancer avec la commande suivante :

```bash
    reboot
```

## Intaller la librairie SDL 2 sur la VM
> Pour installer la librairie SDL 2 sur la VM, il faut lancer la commande suivante :

```bash
    sudo apt-get install libsdl2-dev
```

## Installer la librairie SDL 2 image sur la VM
> Pour installer la librairie SDL 2 image sur la VM, il faut lancer la commande suivante :

```bash
    sudo apt install libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y
```

## Intaller la SDL 2 mixer sur la VM
> Pour installer la librairie SDL 2 mixer sur la VM, il faut lancer la commande suivante :

```bash
    sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y
```

## Installer la SDL 2 type fonts sur la VM
> Pour installer la librairie SDL 2 type fonts, il faut lancer la commande suivante :

```bash
    sudo apt install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y
```

## Commande lié au projet et à la compilation
### Compilation du projet
> Pour compiler le projet il suffit de se placer dans le dossier du projet
> Et lancer la commande suivante :

```bash
    make
```

### Execution du projet
> Pour executer le programme compiler il suffit de lancer la commande suivante :

```bash
    ./nom_du_projet
```
### Suppression des fichiers .o du dossier
> Pour supprimer les fichiers avec une extension en .o ou bien au moment du dernier commit pour avoir la dernière version du projet disponnible sur le repository, il suffit de lancer la commande suivante :

```bash
    make clean
```

### Suppression des fichiers .o et de l'executable du dossier
> Avant chaque commit il est impératif de ne pas push les fichier .o et le fichier executable !!! et donc il faut lancer la commande qui suis.
> Elle a pour but de supprimer les fichiers avec une extension en .o et le fichier executable il suffit de lancer la commande suivante:

```bash
    make fclean
```
### Executable du jeu
> Pour compiler le jeu, et l'exécuter il suffit ce placer dans le dossier "launcher" et de lancer la compilation puis ensuite de lancer l'execution du jeu
> Voici les commandes a exécuter :

```bash
    cd /launcher/
    make
    ./bomberman
```

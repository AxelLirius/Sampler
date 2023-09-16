#!/bin/bash

###################################################
#               PTS3 - Sampleur
#  Script de connexion et lancement du programme
#           Mise à jour : 19/03/2021
###################################################

# Connexion de l'appareil MIDI (port de sortie) au client d'écriture (port d'entrée) Midi Through

#selon la valeur de hdmi hotplug dans le fichier /boot/config.txt 
#les valeurs des canaux de Qjack changent


aconnect 28:MPD218 14:MIDI Through #hdmi_force_hotplug = 1
aconnect 24:MPD218 14:MIDI Through #normal
aconnect 20:MPD218 14:MIDI Through #hdmi_ignore_hotplug = 1

# Lancement du programme python 
cd ..
pkill -f ./Sampler
make sampler

while true
do
	aplay conf/play.wav
	make lancement
done

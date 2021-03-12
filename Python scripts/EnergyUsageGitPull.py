import shutil
import getpass
import os
from datetime import datetime

#User input
root_src_dir = input("Geef het absolute pad naar de bron. Gebruik een base-directory met subitems: ")
root_target_dir = input("Geef het absolute pad naar de bestemming. Gebruik een base-directory: ")

#Datetime object met current datetime vaststellen
now = datetime.now()

#Converteer DateTiem object naar string
timestampStr = now.strftime("%d-%b-%Y (%H:%M:%S.%f)")

#Logged-in user vaststellen
currentuser = getpass.getuser()

try:
####Daadwerkelijke copy actie (recursief)
#1) Definieer variablen voor source folder en target folder
#2) os.walk through de source folder
#3) Gebruik string.replace() om de juiste paden of subfolders in de target folder te krijgen
#4) Als de subfolders niet bestaan, maak ze dan!
#5) Alle bestanden in huidige subfolder, eerst verwijderen. Dan maken of verplaatsen van source folder naar target folder, afhanklijk van operation flag

    operation = 'copy' # Beschikbare flags: 'copy' of 'move'
    for src_dir, dirs, files in os.walk(root_src_dir):
        dst_dir = src_dir.replace(root_src_dir, root_target_dir)

    if not os.path.exists(dst_dir):
        os.mkdir(dst_dir)

    for file_ in files:
        src_file = os.path.join(src_dir, file_)
        dst_file = os.path.join(dst_dir, file_)

    if os.path.exists(dst_file):
        os.remove(dst_file)

    if operation == 'copy':
        shutil.copy(src_file, dst_dir)

    elif operation == 'move':
        shutil.move(src_file, dst_dir)

#Append of maak logfile met copy acties in root van root_target_dir base-directory
#File access mode ‘a’, open() function controleert of de file al bestaat.
#Indien het niet bestaat, wordt het gemaakt. Indien wel, wordt er een regel aan toegevoegd (append).
    file_object = open(os.path.join(root_target_dir, 'copylog.txt'), 'a')
    file_object.write(timestampStr + ': Nieuwe copy actie door user ' + currentuser + ' ' + root_src_dir + ' => ' + root_target_dir)
    file_object.close() #Close object handle
except:
    print("Er is een fout opgetreden bij het kopieren van bestand en/of het schrijven naar de logfile. Controleer de filepaths en permissies op het filesystem")
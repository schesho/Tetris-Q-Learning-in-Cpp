# tetris_rl

c++ tetris reinforcement learning project


shapes_rotation c'est tous les types de figures et leurs rotations possible (pareil que chez mansour)

test.cpp c'est le fichier main

Field c'est le truc qui modifie le terrain de jeux (on a seulement les deux dernieres lignes comme chez mansour)

Piece c'est la classe de la piece qui est définie par son type + rotation (check le png) d'où on déduit le shape (qui est un attribut aussi pour simplifier)


pour lancer du terminal : on se met dans le dossier  contenant et:  
g++ test.cpp Field.cpp Piece.cpp -o peuimportelenom
./peuimportelenom


CLion Test
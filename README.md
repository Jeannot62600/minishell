# urshell
# shellby


- Lecture d'une commande sur le prompt/terminal
- Séparation de la ligne en commande (split(";<>")
- Comprends on la commande et on la met dans une structure

struct command{
    int entre
    int sortie
    path script // recherche dans la varenv
    char** arguments

}

- Execute les commandes dans l'ordre (struct*)
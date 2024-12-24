# get_next_line

## Description
Le projet **get_next_line** a pour objectif de créer une fonction capable de lire et de retourner, ligne par ligne, le contenu d'un fichier ou d'une entrée standard. Ce projet est une étape clé dans le cursus de l'école 42, permettant de travailler sur la gestion de la mémoire et la manipulation des chaînes.

## Utilisation
Pour compiler et utiliser la fonction :  
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<taille souhaitée> get_next_line.c
```

- **BUFFER_SIZE** détermine la quantité de données lues en une fois. Adaptez cette valeur en fonction des besoins.

## Étapes de fonctionnement
1. **Vérification des données** : La fonction lit les données du fichier (ou de l'entrée) par blocs de taille `BUFFER_SIZE`. Elle vérifie si ces données contiennent un caractère de saut de ligne (`\n`), indiquant la fin d'une ligne.
2. **Extraction de la ligne** : Lorsqu'un saut de ligne est détecté, la fonction extrait et retourne la ligne, y compris le `\n`.
3. **Mise à jour du buffer** : Après avoir extrait la ligne, la fonction met à jour le buffer pour conserver uniquement les données restantes.


## Exemple d'utilisation
```c
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```
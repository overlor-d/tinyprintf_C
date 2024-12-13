# tinyprintf

## Description
Ce programme implémente une version simplifiée de la fonction `printf` de la bibliothèque standard C, appelée `tinyprintf`. Elle permet d'afficher des chaînes formatées avec plusieurs types de données tout en gérant différents spécificateurs de format.

## Fonctionnalités principales

1. **Affichage des chaînes de caractères** :
   - La fonction `affichage_char` permet d'afficher une chaîne de caractères caractère par caractère.

2. **Conversion de base** :
   - La fonction `trasfo_base` convertit un entier dans une base donnée (par exemple, octal ou hexadécimal).

3. **Gestion des différents types de données** :
   - Affichage de caractères (`%c`)
   - Affichage de chaînes de caractères (`%s`)
   - Affichage d'entiers signés (`%d`)
   - Affichage d'entiers non signés (`%u`)
   - Affichage en octal (`%o`)
   - Affichage en hexadécimal (`%x`)

4. **Gestion des cas spéciaux** :
   - Gestion des chaînes nulles (`(null)` est affiché si une chaîne est `NULL`).
   - Affichage de caractères spéciaux comme `%`.

## Utilisation

### Exemple d'exécution
Voici un exemple d'utilisation du programme dans la fonction `main` :

```c
int main(void)
{
    tinyprintf("%x", 10);
}
```

### Résultat attendu
L'exemple ci-dessus affiche :
```
a
```
Cela correspond à l'affichage de l'entier `10` en hexadécimal.

### Spécificateurs de format supportés
- `%%` : Affiche le caractère `%`
- `%c` : Affiche un caractère
- `%s` : Affiche une chaîne de caractères
- `%d` : Affiche un entier signé
- `%u` : Affiche un entier non signé
- `%o` : Affiche un entier en base octale
- `%x` : Affiche un entier en base hexadécimale (minuscule)

## Structure du code

1. **Fonctions utilitaires** :
   - `t_str` : Calcule la longueur d'une chaîne de caractères.
   - `affichage_char` : Affiche une chaîne de caractères.
   - `trasfo_base` : Convertit un entier en une représentation dans une base spécifique.

2. **Fonctions de gestion des types** :
   - `test_char` : Gère l'affichage des caractères.
   - `test_str` : Gère l'affichage des chaînes de caractères.
   - `test_integer` : Gère l'affichage des entiers signés.
   - `test_unsigned_integer` : Gère l'affichage des entiers non signés.

3. **Fonction principale `tinyprintf`** :
   - Parcourt une chaîne formatée et affiche les données correspondantes en fonction des spécificateurs rencontrés.

## Points d'amélioration
- **Gestion des entiers négatifs en base différente** : Actuellement, la gestion des nombres négatifs pour les bases octale et hexadécimale n'est pas incluse.
- **Retour de la longueur de la chaîne générée** : La fonction `tinyprintf` pourrait renvoyer le nombre de caractères affichés comme `printf`.
- **Ajout d'autres spécificateurs** : Support pour `%f`, `%e`, etc.

## Compilation et exécution
Pour compiler et exécuter le programme :

```bash
gcc -o tinyprintf tinyprintf.c
./tinyprintf
```

## Auteur
jean lepeltier

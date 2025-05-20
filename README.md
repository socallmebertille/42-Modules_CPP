# 42-Modules_CPP

## Quick C++ notes

| Types | What is it | What for |
|---|---|---|
| string | chaine de caractere | a une adresse mémoire unique |
| type* | pointeur | stocke l'adresse du type → il affiche donc la même adresse et son déférencment donne la valeur du type |
| type& | référence | accede au type (= copie d'un type mais pouvant modifier l'origine s'il est modifié) → ont la même adresse |

## Modules

### CPP00 — Bases du C++

| Concepts | Brief explanation |
|---|---|
| Namespaces | utilisation de std pour éviter les conflits de noms |
| Classes | définition de classes simples avec des membres publics et privés |
| Fonctions membres | déclaration et définition de fonctions associées à une classe |
| Flux d'entrée/sortie | utilisation de `std::cout` et `std::cin` pour l'affichage et la saisie |
| Listes d'initialisation | initialisation des membres d'une classe via le constructeur |
| Mots-clés static et const | déclaration de membres constants et statiques |

### CPP01 — Allocation mémoire et références

| Concepts | Brief explanation |
|---|---|
| Allocation dynamique | utilisation de new et delete pour gérer la mémoire |
| Références | passage par référence pour éviter les copies inutiles |
| Pointeurs sur membres | accès aux membres d'une classe via des pointeurs |
| Flux de fichiers | lecture et écriture dans des fichiers avec std::ifstream et std::ofstream |

### CPP02 — Polymorphisme ad hoc et classes canoniques

| Concepts | Brief explanation |
|---|---|
| Surcharge de fonctions | définition de plusieurs fonctions avec le même nom mais des paramètres différents |
| Forme canonique | implémentation des quatre fonctions spéciales : constructeur par défaut, constructeur de copie, opérateur d'affectation et destructeur |
| Gestion de la mémoire | allocation et désallocation appropriées pour éviter les fuites mémoire |

### CPP03 — Héritage simple et polymorphisme

| Concepts | Brief explanation |
|---|---|
| Héritage | création de classes dérivées à partir de classes de base |
| Polymorphisme | utilisation de fonctions virtuelles pour permettre le comportement dynamique |
| Constructeurs et destructeurs | ordre d'appel dans une hiérarchie de classes |

### CPP04 — Héritage multiple et classes abstraites
Objectif : Approfondir l'héritage multiple et les classes abstraites.

| Concepts | Brief explanation |
|---|---|
| Héritage multiple | création de classes dérivées de plusieurs classes de base |
| Classes abstraites | définition de classes avec des fonctions virtuelles pures |
| Interfaces | mise en place d'interfaces pour définir des comportements communs |

### CPP05 — Gestion des exceptions

| Concepts | Brief explanation |
|---|---|
| Exceptions | utilisation des blocs try, catch et throw pour gérer les erreurs |
| Types d'exceptions | création de classes d'exception personnalisées |
| Propagation des exceptions | transmission des exceptions à travers les appels de fonctions |

### CPP06 — Casts et conversions de types

| Concepts | Brief explanation |
|---|---|
| Casts C++ | utilisation de static_cast, dynamic_cast, const_cast et reinterpret_cast |
| Conversions implicites et explicites | compréhension des conversions automatiques et forcées |
| Sécurité des conversions | identifier les conversions sûres et celles potentiellement dangereuses |

### CPP07 — Templates et programmation générique

| Concepts | Brief explanation |
|---|---|
| Templates de fonctions | définition de fonctions génériques pour différents types |
| Templates de classes | création de classes génériques |
| Spécialisation de templates | personnalisation du comportement pour des types spécifiques |

### CPP08 — Conteneurs standards et algorithmes STL

| Concepts | Brief explanation |
|---|---|
| Conteneurs STL | utilisation de std::vector, std::list, std::map, etc |
| Itérateurs | parcours des conteneurs avec des itérateurs |
| Algorithmes STL | application d'algorithmes comme std::sort, std::find, etc |

### CPP09 — Projet final intégrant tous les concepts

| Concepts | Brief explanation |
|---|---|
| Intégration des modules précédents | application des concepts d'orientation objet, de gestion de la mémoire, de templates, etc |
| Optimisation du code | amélioration des performances et de la lisibilité |
| Gestion des erreurs | mise en place d'une gestion robuste des exceptions |

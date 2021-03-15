const MONMAX=10;
struct abonnement 
{
    int identifiant;
    char nomabn[100];
    int prix;
    int nombreCredit;
};

typedef struct abonnement abonnement;

enum typeCompte
{
    client,
    gestionnaire
};

typedef enum typeCompte typeCompte;
enum step
{
    engage,
    abonne,
    resilie
};
typedef enum step step;

struct date{
    int jour;
    int mois;
    int annee;
};
typedef struct date date;

struct engagement
{
    abonnement abn;
    date debut;
    date fin;
    step etat;
};
typedef struct engagement engagement;

struct compte
{
    char nom[100];
    char prenom [100];
    int identifiant;
    char mdp[32];
    char adresse[250];  
    engagement monEngagement;
    typeCompte monType;
};
typedef struct compte compte;

struct collection
{
    char nomCollection [100];
    int idCollection;
};
typedef struct collection collection;


struct vetement
{
    char nomVetement[100];
    int prixVetement;
    int nbCredit;
    int idVetement;
    int nbExemplaire;
    collection maCollection;
};
typedef struct vetement vetement;


enum stepLocation
{
    louer,
    rendu
};
typedef enum stepLocation stepLocation;

struct location
{
    date debut_location;
    date fin_location;
    stepLocation etatDeLaLocation;
    int identifiantClient;
    int identifiantVetement; 
    int identifiantLocation;
};
typedef struct location location;

enum boolean
{
    reussi,
    echoue
};
typedef enum boolean boolean;


program PANOPLYPROG{
    version PANOPLYVERS{
/*
    les fonctions renvoyant un boolean donne true si l'exectuion c'est bien passé et false sinon
*/ 

    /*gestion compte*/
        /*permet de creer un compte*/
        boolean CREERCOMPTE(compte)=1;
        /*permet de se connecter*/
        boolean SECONNECTER(compte)=2;
        /*permet d'afficher un compte*/
        compte AFFICHERCOMPTE(int)=3;
        /* permet de recuperer la varialble globale contenant le nombre de compte*/
        int NOMBRECOMPTE()=4;
    
    /*gestion abonnement*/       
        boolean CREERABONNEMENT(abonnement)=5;
        /* permet de recuperer la varialble globale contenant le nombre d'abonement*/
        int NOMBREABONNEMENT()=6;
        /*permet d'afficher un abonnement*/
        abonnement AFFICHERABONNEMENT(int)=7;
        /*permet de metre a jour un abonnement*/
        boolean MAJUNABONNEMENT(abonnement)=8;
        /*affecter un abonement a un compte */
        boolean AFFECTATIONABONNEMENT(compte)=9;
    
    /*gestion collection*/
        /*creation d'une collection*/
        boolean CREERCOLLECTION(collection)=10;
        /*permet d'obtenir le nombre de collection*/
        int NOMBRECOLLECTION()=11;
        /*renvoie une collection*/
        collection AFFICHERCOLLECTION(int)=12;
        /*permet de mettre dans une tj_vetement_collection les vetement d'une collection*/
        /*tj_vetement_collection LISTERCOLLECTIONVETEMENT(int)=13;*/
        boolean ASSOCIERVETEMENTCOLLECTION(vetement)=13;
    
    /*gestion vetement*/
        /*creation d'un vetement*/
        boolean CREERVETEMENT(vetement)=14;
        /*pour la recherche d'un vetement on recherche par l'id .On peut aussi par le nom*/
        vetement AFFICHERVETEMENT(int)=15;
        int NOMBREVETEMENT()=16;

    /*gestion location*/
        boolean LOUERVETEMENT(location)=17;
        int NOMBRELOCATION ()=18;
        location AFFICHERLOCATION(int)=19;
   

    } = 1;
}= 0x23456780;

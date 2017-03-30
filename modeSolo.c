#include "modesoloh"

void solo(){
    /**Appel de la fonction de phase d'attaque de l'IA*/
    attaque();
    /**Appel de la fonction de phase de défense de l'IA*/
    defense();
}

void attaque(){
/**Zone de variables*/

    /**Parcourir le tableau*/
    /**Alignés sur une ligne et pas de pions en dessous*/
    if(3 pions à côté sur une même ligne && case à côté libre && case en dessous de la case à côté pleine){ 
        poser un pion
    }else{
        /**Alignés sur une ligne et pions en dessous*/
        if(3 pions à côté sur une même ligne && case à côté libre && case en dessous de la case à côté pleine){
            poser un pion
        }else{
            /**Sur une même colonne*/
            if(3 pions alignés sur la même colonne && case au dessus libre){
                poser un pion
            }else{
                /**EN diagonale vers la droite*/
                if(3 pions alignés en colonne vers la droite && case à droite du dernier point occupée && case au dessus à droite libre){
                    poser un pion
                 }else[
                     /*En diagonale vers la gauche*/
                    if(3 pions alignés en colonne vers la gauche && case à gauche du dernier point occupée && case au dessus à gauche libre){
                        poser un pion
                    }else{
                        générer un nombre aléatoire et poser un pion
                    }
                ]  
            }
        }
    }
}
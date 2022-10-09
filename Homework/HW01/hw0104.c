#include <stdio.h>

int main() {
    //setup
    int lvl, atk, def, pwr, weather, aType, tType, stat, terr, mType, mCat;
    printf("Attacker\n");
    printf("    level: ");
    scanf("%d", &lvl);
    printf("    atk: ");
    scanf("%d", &atk);
    printf("    type: ");
    scanf("%d", &aType);
    printf("    status: ");
    scanf("%d", &stat);
    printf("    move power: ");
    scanf("%d", &pwr);
    printf("    move type: ");
    scanf("%d", &mType);
    printf("    move category: ");
    scanf("%d", &mCat);

    printf("Target:\n");
    printf("    def: ");
    scanf("%d", &def);
    printf("    type: ");
    scanf("%d", &tType);

    printf("Environment\n");
    printf("    weather: ");
    scanf("%d", &weather);
    printf("    terrain: ");
    scanf("%d", &terr);

    //weather effect recognition
    double weather_effect = 1;
    if(weather==1){
        if(aType==0){
            weather_effect = 0.5;
        }
        else if(aType==1){
            weather_effect = 2;
        }
        else{
            weather_effect = 1;
        }
    }
    else if(weather==2){
        if(aType==0){
            weather_effect = 2;
        }
        else if(aType==1){
            weather_effect = 0.5;
        }
        else{
            weather_effect = 1;
        }
    }
    else{
        weather_effect = 1;
    }

    //type effect recognition
    double type = 1;
    if(aType==0){
        if(tType==0 || tType==2 || tType==7){
            type = 0.5;
        }
        if(tType==1 || tType==4 || tType==5){
            type = 2;
        }
        else{
            type = 1;
        }
    }
    else if(aType==1){
        if(tType==0 || tType==1 || tType==4 || tType==7){
            type = 0.5;
        }
        else if(tType==2){
            type = 2;
        }
        else{
            type = 1;
        }
    }
    else if(aType==2){
        if(tType==1 || tType==2 ||tType==3 || tType==7){
            type = 0.5;
        }
        else if(tType==0 || tType==4 || tType==5){
            type = 2;
        }
        else{
            type = 1;
        }
    }
    else if(aType==3){
        if(tType==4 || tType==6){
            type = 0.5;
        }
        else if(tType==2){
            type = 2;
        }
        else{
            type = 1;
        }
    }
    else if(aType==4){
        if(tType==5){
            type = 0.5;
        }
        else if(tType==1 || tType==3){
            type = 2;
        }
        else{
            type = 1;
        }
    }
    else if(aType==5){
        if(tType==3){
            type = 0;
        }
        else if(tType==1 || tType==4 || tType==6){
            type = 2;
        }
        else{
            type = 1;
        }
    }
    else if(aType==6){
        if(tType==5){
            type = 0;
        }
        else if(tType==2 || tType==6 || tType==7){
            type = 0.5;
        }
        else if(tType==0 || tType==3){
            type = 2;
        }
        else{
            type = 1;
        }
    }
    else if(aType==7){
        if(tType==7){
            type = 2;
        }
    }

    //status effect
    double stat_effect = 1;
    if(stat==1 && mCat==0){
        stat_effect = 0.5;
    }
    if(stat==2 && mCat==1){
        stat_effect = 0.5;
    }

    //terrain effect
    double terr_effect = 1;
    if(terr==1 && aType==2){
        terr_effect = 2;
    }
    if(terr==2 && aType==6){
        terr_effect = 2;
    }
    if(terr==3 && aType==7){
        terr_effect = 0.5;
    }

    //miscellaneous
    if(weather==5 && tType==4){
        def *= 2;
    }
    if(weather==2 && tType==5){
        def /= 2;
    }
    if(weather==3 && aType==2){
        atk /= 2;
    }
    if(weather==4 && aType==3){
        atk *= 2;
    }

    //stab
    int stab;
    if (aType == mType) {
        stab = 2;
    } else {
        stab = 1;
    }
    double factor = weather_effect*stab*type*stat_effect*terr_effect;
    double first_damage = ((lvl*2+10)*atk*pwr/def/250);
    double damage = (((int)first_damage+2)*factor);

    printf("Damage --> %d", (int)damage);
    return 0;
}


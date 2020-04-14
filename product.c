#include "product.h" 

int addProduct(Product *p){
    printf("제품명은? ");
    scanf("%[^\n]", p->name);

    printf("중량은? ");
    scanf("%d", &p->weight);

    printf("가격은? ");
    scanf("%d", &p->price);

    p->st_price = p->price * 10 / p->weight;

    while(1){
        printf("별점수는?(1~5) ");
        scanf("%d", &p->grade);

        if(p->grade > 5 || p->grade < 1)
            printf("별점수를 다시 입력하세요. \n");
        else
            break;
 Worl://github.com/sunghwan97/mini_project.git   }
    
    return 1;
}

void readProduct(Product p){
    if(p.weight == -1 && p.price == -1 && p.grade == -1){
        return;
    }

    printf("    %d  %d   %d      %d    %s\n", p.weight, p.price, p.st_price, p.grade, p.name);
}

int updateProduct(Product *p){
    printf("제품명은? ");
    scanf("%[^\n]", p->name);

    printf("중량은? ");
    scanf("%d", &p->weight);

    printf("가격은? ");
    scanf("%d", &p->price);

    p->st_price = p->price * 10 / p->weight;

    while(1){
        printf("별점수는?(1~5) ");
        scanf("%d", &p->grade);

        if(p->grade > 5 || p->grade < 1)
            printf("별점수를 다시 입력하세요. \n");
        else
            break;
    }
    
    printf("=> 수정성공!\n");

    return 1;
}

int deleteProduct(Product *p){
    p->weight = -1;
    p->price = -1;
    p->st_price = -1;
    p->grade = -1;
    
    return 1;
}

void saveData(Product *p, int count){
    FILE *fp;
    
    fp = fopen("product.txt", "wt");
    
    for(int i = 0; i < count; i++){
        if(p[i].price != -1)
            fprintf(fp, "%d %d %d %d %s\n", p[i].price, p[i].weight, p[i].st_price, p[i].grade, p[i].name);
    }
    fclose(fp);

    printf("저장됨!");
}

int loadData(Product p[]){
    int count = 0;
    FILE *fp;

    fp = fopen("product.txt", "rt");
    if(fp == NULL){
        printf("=> 파일 없음\n");
        return 0;
    }

    for(; ; count++){
        fscanf(fp, "%d", &p[count].price);
        fscanf(fp, "%d", &p[count].weight);
        fscanf(fp, "%d", &p[count].st_price);
        fscanf(fp, "%d", &p[count].grade);
        fscanf(fp, "%[^\n]", p[count].name);

        if(feof(fp)) break;
    }

    fclose(fp);
    printf("=> 로딩 성공!\n");

    return count;
}

void searchName(Product *p, int count){

}

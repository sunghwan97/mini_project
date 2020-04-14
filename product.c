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
    }
    
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

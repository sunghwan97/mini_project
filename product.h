#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50]; // 제품명
    int weight; // 중량
    int price; // 가격
    int st_price; // 표준가격(10g당 가격)
    int grade; // 별점수
} Product;

int addProduct(Product *p); // 제품을 추가하는 함수
void readProduct(Product p); // 하나의 제품을 출력하는 함수
int updateProduct(Product *p); // 제품을 수정하는 함수
int deleteProduct(Product *p); // 제품을 삭제하는 함수
void saveData(Product *p, int count); // 파일을 저장하는 함수
int loadData(Product p[]);  // 파일을 불러오는 함수
void searchName(Product *p, int count); // 제품을 검색하는 함수(함수에서 경우의 수를 나눠서 3가지 이상 검색이 가능하도록 구현할 예정)

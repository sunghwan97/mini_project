//2020OSS mini_project
#include "manager.h"
#define DEBUG

int selectMenu();

int main(void){
#ifdef DEBUG
    printf("debug[market.c]");
#endif
    Product *mp[100];
    int count = 0, menu, curcount = 0;
    
    count = loadData(mp);
    curcount = count;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0){
                listProduct(mp, curcount);
            } else{
                printf("데이터가 없습니다! \n");
            } 
        }
        else if (menu == 2){
	    mp[curcount] = (Product *)malloc(sizeof(Product));
            count += addProduct(mp[curcount++]);
            printf("=> 추가됨! \n");
        }
        else if (menu == 3){
	    int no = selectDataNo(mp, curcount);
	    if(no == 0){
            	printf("=> 취소됨! \n");
		continue;
	    }
            updateProduct(mp[no-1]);
        }
        else if (menu == 4){
	    int no = selectDataNo(mp, curcount);
	    if(no == 0){
            	printf("=> 취소됨! \n");
		continue;
	    }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제: 1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(mp[no-1]) free(mp[no-1]);
		mp[no-1] = NULL;
		count--;
            }
        }
        else if(menu == 5){
            if(count == 0){
                printf("데이터가 없습니다!\n");
            } else{
                saveData(mp, curcount);
            }
        }
        else if(menu == 6){
            searchName(mp, count);
        }
    }
    printf("종료됨!\n");
    return 0;
}

int selectMenu(){
    int menu;
    printf("\n*** 과자 관리 프로그램 ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();
    return menu;
}

#include <stdio.h>
#include <stdlib.h>
#define FEED_POINT 10

void printVandingMachine(int);
int askingLabel();
int printFeed();

int main()
{
    int point = 0;
    int yesNo = 0;
    int input = 0; //캔과 페트병을 투입할 때
    int canAmount = 0;
    int petAmount = 0;
    int peopleCount = 0; //누적 사용인원
    int sum = 0;
    int feed = 0; //간식, 사료 선택

    while (1)
    {
        //자판기그림 출력
        printVandingMachine(peopleCount);

        //시작여부
        while (1)
        {
            printf("시작하시겠습니다까? (네:1, 아니오:2): ");
            scanf("%d", &yesNo);

            if (yesNo == 2)
            {
                peopleCount += 1;
                break;
            }
            else
            {
                peopleCount += 1;
                break;
            }
        }

        if (yesNo == 1)
        {

            //상표정리 하였는지의 여부를 묻는 출력문
            askingLabel();

            //캔과 페트병의 개수 입력
            sum = printFeed();

            //총포인트의 합계
            printf("\n캔:%d개, 페트병:%d개, 합계:%d 포인트 \n", canAmount, petAmount, sum - FEED_POINT);
            printf("============================================ \n\n\n\n\n\n\n\n\n\n\n");
        }
    }

    return 0;
}

//자판기그림 출력
void printVandingMachine(int peopleCount)
{
    int point = 0;

    printf("\n---------------------안녕하세요.----------------------\n");
    printf("|  동네 고양이, 강아지들을 지키는 재활용 자판기입니다.|\n");
    printf("|캔은 한 개당 7point, 페트병은 한 개당 5point입니다.  |\n");
    printf("|자판기에 %d포인트가 쌓일 때마다 사료 80g이 나옵니다. |\n", FEED_POINT);
    printf("|                                                     |\n");
    printf("|-------------------------주의사항--------------------|\n");
    printf("|   상표 등을 분리하지 않을 시 point가 무효 됩니다.   |\n");
    printf("|  캔과 페트병은 한번에 하나씩만 투입할 수 있습니다.  |\n");
    printf("|                                                     |\n");
    printf("|           현재까지 %d명이 함께해주셨습니다.          |\n", peopleCount);
    printf("|                                                     |\n");
    printf("-------------------------------------------------------\n");
    printf("\n\n\n\n\n");

    return;
}

//상표정리 하였는지의 여부를 묻는 출력문
int askingLabel()
{
    int yesNo = 0;
    while (1)
    {
        printf("재활용품의 상표 등을 제거하셨습니까? (네:1, 아니오:2, 종료:3): ");
        scanf("%d", &yesNo);

        if (yesNo == 1)
        {
            break;
        }
        else if (yesNo == 2)
        {
            printf("상표 제거 후 다시 진행해주시기 바랍니다. \n\n");
            continue;
        }
        else
        {
            break;
        }
    }

    return yesNo;
}

//캔과 페트병 개수 입력, 포인트 도달 시 사료,간식
int printFeed()
{
    int input = 0, canAmount = 0, petAmount = 0, feed = 0, point = 0, sum = 0;

    while (1)
    {
        printf("캔: 1번, 페트병: 2번, 종료: 3번 \n");
        scanf("%d", &input);

        if (input == 1)
        {
            canAmount += 1;
        }
        else if (input == 2)
        {
            petAmount += 1;
        }
        else
        {
            break;
        }

        //총 포인트계산
        sum = point + (canAmount * 7) + (petAmount * 5);

        //포인트가 100이 넘으면 사료!!
        if (sum >= FEED_POINT)
        {
            printf("사료는 1번, 간식은 2번: ");
            scanf("%d", &feed);

            if (feed == 1)
            {
                printf("\n\n당신의 도움으로 소중한 생명을 지킬 수 있게 되었습니다. (사료)\n\n");
            }
            else if (feed == 2)
            {
                printf("\n\n당신의 도움으로 소중한 생명을 지킬 수 있게 되었습니다. (간식)\n\n");
            }
            else
            {
                printf("1,2번 중 재입력 요망 \n");
            }

            point = point - FEED_POINT;
            printf("현재 포인트: %d 포인트 \n", sum - FEED_POINT);
            continue;
        }
        else
        {
            continue;
        }
    }

    return sum;
}

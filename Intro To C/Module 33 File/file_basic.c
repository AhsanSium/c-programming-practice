#include<stdio.h>

//int main()
//{
//    int n, sum = 0;
//    scanf("%d", &n);
//
//    int arr[n];
//
//    for(int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        sum = sum + arr[i];
//    }
//
//    printf("Sum Is %d", sum);
//
//    return 0;
//
//}

int main()
{
    FILE *input_File;

    input_File = fopen("input.txt", "r");

    if( input_File == NULL )
    {
        printf("No File Found \n");

        return 0;
    }

    FILE *output_file;

    output_file = fopen("output.txt", "w");

    while(1)
    {
        char ch = fgetc(input_File);

        if(ch == EOF)
        {
            break;
        }
        printf("%c", ch);

        fputc( ch, output_file);
    }


    return 0;
}

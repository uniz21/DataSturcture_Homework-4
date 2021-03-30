#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [������]  [2016039040] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");
    //��� ���� ũ�⸦ �Է¹޾� ����� ����
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    //����� ������� ��� ������ ����
    if (matrix_a == NULL || matrix_b == NULL) { return -1; }

    do {
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch (command) {
        case 'z': case 'Z'://��� �ʱ�ȭ
            //�� ����� ũ��� ������ ä�� ���ο� ����� �����Ѵ�.
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P'://��� ���
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A'://����� ��
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S'://����� ��
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T'://��ġ���
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            break;
        case 'm': case 'M'://���A�� A�� ��ġ���T�� ��
            //��ġ���T ����
            printf("matrix_t\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            printf("Multiply matrix_a with transposed matrix_a \n");
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q'://����
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    /* check pre conditions */
    // ��� ���� ũ�� Ȯ��
    if (row <= 0 || col <= 0) {
        printf("Check the sizes of row and col!\n");
        return NULL;
    }

    //���� �޸� �Ҵ����� ��� ����
    int **x;
    x=malloc(row * sizeof(*x));
    for (int i = 0; i < row; i++)
        x[i]=malloc(col * sizeof(**x));
    //���ä���
    fill_data(x, row, col);
    //��� ��ȯ
    return x;
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    /* check pre conditions */
    if (matrix == NULL) {
        printf("Matrix broken");
        return -1;
    }
    
    //��*�� ��ŭ �ݺ��Ͽ� ���а� ���
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < col; k++) {
            printf("%d ", matrix[i][k]);
        }
        printf("\n");
    }
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    //���� �޸��Ҵ� ����
    for (int i = 0; i < row; i++)
            free(matrix[i]);
    free(matrix);
    return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    //��*���� ũ�⸸ŭ �ݺ�
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
            //0~19 ������ ������ ����
            matrix[i][k] = rand()%20;
    }
    return 1;
    /* check post conditions */
    if (matrix == NULL) {
        printf("Matrix broken");
        return -1;
    }
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_sum = create_matrix(row, col);
    //��*���� ũ�⸸ŭ �ݺ�
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            //A��İ� B����� ���� �����ϴ� ������ ��
            matrix_sum[i][k] = matrix_a[i][k] + matrix_b[i][k];
        }
    }
    print_matrix(matrix_sum, row, col);
    /* check post conditions */
    if (matrix_sum == NULL) {
        printf("Add Failed");
        return -1;
    }
    return 1;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_sub = create_matrix(row, col);
    //��*���� ũ�⸸ŭ �ݺ�
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            //A��İ� B����� ���� �����ϴ� ������ ��
            matrix_sub[i][k] = matrix_a[i][k] - matrix_b[i][k];
        }
    }
    print_matrix(matrix_sub, row, col);
    /* check post conditions */
    if (matrix_sub == NULL) {
        printf("Sub Failed.");
        return -1;
    }
    return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    //��*���� ũ�⸸ŭ �ݺ�
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            //��ġ����� ��� ���� �ݴ��̴�.
            matrix_t[i][k] = matrix[k][i];
        }
    }
    print_matrix(matrix_t,row,col);
    /* check post conditions */
    if (matrix_t == NULL) {
        printf("Transpose Failed.");
        return -1;
    }
    return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    /* check pre conditions */
    //��ġ��� T�� �������� ���� ���
    if (matrix_t == NULL) {
        printf("Check about Transpose Matrix A");
        return -1;
    }
    //��� A�� A�� ��ġ��� T�� ���̹Ƿ� ��ó���� ����� ũ�⸦ ���� �ʿ�� ����.

    int** matrix_axt = create_matrix(row, row);
    int sum=0;
    //����� �� ��Ģ�� ���� �� ����� ��*���� ũ�⸦ ���� ����� �����ȴ�.
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < row; k++)
        {
            //�� ����� ���� �� ����� �࿡ ���� ���� ����
            for (int t = 0; t < col; t++) 
            {
                sum+=matrix_a[i][t] * matrix_t[t][k];
            }
            matrix_axt[i][k] = sum;
            sum = 0;
        }
    }
    print_matrix(matrix_axt,row,row);
    
    /* check post conditions */
    if (matrix_axt == NULL) {
        printf("Multiply Failed.");
        return -1;
    }
    return 1;
}
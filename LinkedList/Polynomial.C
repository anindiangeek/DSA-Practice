#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *create()
{
    Node *poly = nullptr;
    struct Node *t, *last = NULL;
    int num = 0;

    printf("\nEnter number of terms");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp\n");

    for (int i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
            poly = last = t;
        else
        {
            last->next = t;
            last = t;
        }
    }
    return poly;
}

struct Node *append(struct Node *thead, int c, int e)
{
    struct Node *newPOLYNO = (struct Node *)malloc(sizeof(struct Node));
    newPOLYNO->coeff = c;
    newPOLYNO->exp = e;
    if (thead == NULL)
    {
        newPOLYNO->next = NULL;
        return newPOLYNO;
    }
    struct Node *trav = thead;
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = newPOLYNO;
    newPOLYNO->next = NULL;
    return thead;
}
struct Node *ADD(Node *P1, Node *P2)
{
    struct Node *ans = NULL, *itr = NULL;
    struct Node *t1 = P1, *t2 = P2;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp > t2->exp)
        {
            ans = append(ans, t1->coeff, t1->exp);
            t1 = t1->next;
        }
        else if (t1->exp < t2->exp)
        {
            ans = append(ans, t2->coeff, t2->exp);
            t2 = t2->next;
        }
        else
        {
            ans = append(ans, (t1->coeff) + (t2->coeff), t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1 != NULL)
    {
        ans = append(ans, t1->coeff, t1->exp);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        ans = append(ans, t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return ans;
}

struct Node *new_POLYNO()
{
    struct Node *t1;
    t1 = (struct Node *)malloc(sizeof(struct Node));
    return t1;
}

struct Node *MULTIPLY(struct Node *h1, struct Node *h2)
{
    struct Node *ptr, *p1, *p2, *h3 = NULL, *prev;
    p1 = h1;
    ptr = new_POLYNO();
    h3 = ptr;
    while (p1 != NULL)
    {
        p2 = h2;
        while (p2 != NULL)
        {
            ptr->coeff = p1->coeff * p2->coeff;
            ptr->exp = p1->exp * p2->exp;
            p2 = p2->next;
            ptr->next = new_POLYNO();
            ptr = ptr->next;
        }
        p1 = p1->next;
    }
    p1 = h3;
    while (p1->next != NULL)
    {
        prev = p1;
        p2 = p1->next;
        while (p2 != NULL)
        {
            if (p1->exp == p2->exp)
            {
                p1->coeff = p1->coeff + p2->coeff;
                prev->next = p2->next;
                free(p2);
                p2 = prev->next;
            }
            else
            {
                prev = p2;
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
    return h3;
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *P1 = create();
    Node *P2 = create();
    Node *P3 = ADD(P1, P2);
    puts("Addition is :");
    Display(P3);
    return 0;
}
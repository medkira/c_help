#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
bool check_card_number(const char *card);
void check_card_type(const char *card);

int main(void)
{
    char card[20];
    printf("Entrez le numéro de carte : ");
    scanf("%19s", card);

    if (check_card_number(card))
    {
        check_card_type(card);
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

bool check_card_number(const char *card)
{
    int length = strlen(card);
    int sum = 0;
    bool should_double = false;

    for (int i = length - 1; i >= 0; i--)
    {
        if (!isdigit(card[i]))
            return false;
        int digit = card[i] - '0';
        if (should_double)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }
        sum += digit;
        should_double = !should_double;
    }
    return (sum % 10 == 0);
}

void check_card_type(const char *card)
{
    int length = strlen(card);

    if ((length == 15 && (strncmp(card, "34", 2) == 0 || strncmp(card, "37", 2) == 0)))
    {
        printf("AMEX\n");
    }
    else if ((length == 16 && (strncmp(card, "51", 2) == 0 || strncmp(card, "52", 2) == 0 ||
                               strncmp(card, "53", 2) == 0 || strncmp(card, "54", 2) == 0 ||
                               strncmp(card, "55", 2) == 0)))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && card[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

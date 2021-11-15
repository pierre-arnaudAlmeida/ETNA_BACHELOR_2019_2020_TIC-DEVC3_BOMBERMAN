/*
    Compte le nombre d'itérations du caractère dans un string
*/
int search_iteration(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
    	if (str[i] == c)
            count++;

 	return count;	  
}

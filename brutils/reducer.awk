#!/usr/bin/awk -f
# assumes
# key value columns (2)
# whitespace separated
# sorted input
BEGIN {
    data_count = 0;
}
{
#1  key
#2. value

    if($1 != current_key)
    {
        if((current_key) && !(current_key ~ /^#/))
        {
            printf ("%s %16d\n", current_key, current_value_sum);
        }
        current_key = $1;
        current_value_sum = $2;
    }
    else
    {
        current_value_sum += $2;
    }

    data_count++;
}
END {
    if(!(current_key ~ /^#/))
    {
        printf ("%s %16d\n", current_key, current_value_sum);
    }    
}

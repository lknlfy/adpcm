#include <stdio.h>
#include <string.h>
#include "adpcm.h"


adpcm_state_t adpcm_state;
adpcm_state_t adpcm_state2;

#define DATA_LEN   (8)


int main()
{
    /* make data only for test */
    short original_data[DATA_LEN] = {10, 20, 30, 40, 50, 60, 70, 80};
    char encoded_data[DATA_LEN / 2];
    short decoded_data[DATA_LEN];
    int i;

    memset(&adpcm_state, 0, sizeof(adpcm_state));
    memset(&adpcm_state2, 0, sizeof(adpcm_state2));

    /* encode original data */
    adpcm_coder((short *)original_data, encoded_data, sizeof(original_data), &adpcm_state);

    /* printf encoded data */
    printf("\nencoded data: \n");
    for (i = 0; i < sizeof(encoded_data); i++)
        printf("0x%x\n", encoded_data[i]);

    /* decode encoded data */
    adpcm_decoder(encoded_data, (short *)decoded_data, sizeof(encoded_data), &adpcm_state2);

    /* printf decoded data */
    printf("\ndecoded data: \n");
    for (i = 0; i < DATA_LEN; i++)
        printf("%d\n", decoded_data[i]);

    return 0;
}

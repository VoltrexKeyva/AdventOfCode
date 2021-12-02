#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../misc/ioutil.h"
#include "../../misc/arrayutil.h"

int main(void) {
    char * data = read_file("../input.txt");

    array_t parsed = parse_array(data);
    array_t nums = new_array();
    
    nums->size = 3;
    memcpy(nums->data, parsed->data, 3 * sizeof(uint16_t));
    
    uint16_t previous_sum = parsed->data[0] + parsed->data[1] + parsed->data[2];
    uint16_t times_increased = 0;
    parsed->size -= 2;
    
    for (uint16_t i = 1; i < parsed->size; i++) {
        append_array(nums, parsed->data[i + 2]);
        
        const uint16_t current_sum = nums->data[i] + nums->data[i + 1] + nums->data[i + 2];
        if (current_sum > previous_sum)
            times_increased++;
        
        previous_sum = current_sum;
    }
    
    printf("%d\n", times_increased);
    
    free(nums->data);
    free(nums);
    
    free(parsed->data);
    free(parsed);
    
    free(data);
    return 0;
}
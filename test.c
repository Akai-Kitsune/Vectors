
/*
Copyright (C) 31.08.2021 Aleksei Likhachev
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the KI General Public License version for more details.
*/

#include "kVectors.h"

void test1(void){
    
	__vector2_float* vec1 =  vector2_create_float();
	__vector2_float* vec2 =  vector2_create_float();
	__vector2_float* vec3 =  vector2_create_float();
    __vector2_double* vec4;
    
	vector2_init_float(vec1, 12.0, 1.5);
	vector2_init_float(vec2, -1.0, 1.5);
	vector2_add_float(vec3, vec1, vec2);
    
    vec4 = vector2_normalize_float(vec3);
    
	printf("%f %f %f\n", vec4->x, vec4->y, vector2_norm_float(vec3));
    
    free(vec1);
    free(vec2);
    free(vec3);
}

void test2(void){
	__vectorN_float* vec1 = vectorN_create_float();
	float* arr1 = malloc(2*sizeof(float));
	arr1[0] = -1.0;
	arr1[1] = 1;
	vectorN_init_float(vec1, arr1, 2);

	__vectorN_float* vec2 = vectorN_create_float();
	float* arr2 = malloc(3*sizeof(float));
	arr2[0] = 1;
	arr2[1] = 1;
	arr2[2] = 4;
	vectorN_init_float(vec2, arr2, 3);

	__vectorN_float* vec3 = vectorN_create_float();
	vectorN_init_float(vec3, arr2, 3);
	vectorN_add_float(vec3, vec1, vec2);

	printf("%f\n%f\n%f\n", vec3->data[0], vec3->data[1], vec3->data[2]);
}

void testXLN(void){
    xln *n1 = xln_alloc(5), *n2 = xln_alloc(5), *n3 = xln_alloc(11);
    xln_init_string(n1, "1");
    xln_init_string(n2, "2");
    xln_init_string(n3, "3");

    void* ptr[3] = {n1, n2, n3};
    __vector_xln* v = vector_create_xln(3);
    vector_init_xln(v, (xln**)ptr, 3);
}

int main(void){
	// In documentation
	testXLN();
	return 0;
}

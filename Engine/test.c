#include <stdio.h>
#include "Handle.h"
int main(){
	HandleManager manager = HM_createHandleManager();
	int* test_ptr;
	int* test_ptr2;
	int* test_ptr3;
	int a = 10;
	int b = 33;
	int c = 33;
	test_ptr = &a;
	test_ptr2 = &b;
	test_ptr3 = &b;
	uint32_t handle = HM_genHandle(&manager,test_ptr,3);
	uint32_t handle2 = HM_genHandle(&manager,test_ptr2,1);
	HM_removeHandle(&manager,handle);
	uint32_t handle3 = HM_genHandle(&manager,test_ptr3,1);
	if(HM_getHandleReturn(&manager, handle) == NULL){
		printf("yaj");
	}
	return 0;
}

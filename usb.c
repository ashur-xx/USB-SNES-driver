#include "usb.h"


int main(void){
//	printf("SizeOF %ld\n", sizeof(struct usb_dev_handle*));
    libusb_init();
    libusb_set_debug(2);
    libusb_find_busses();
    libusb_find_devices();


	struct usb_dev_handle* green = malloc(256);
	green = get_green(bus, dev);
	printf("Detach: %d\n", usb_detach_kernel_driver_np(green, 0));
	printf("Halt: %d\n", usb_clear_halt(green, 0x81));
	printf("Interface: %d\n", usb_claim_interface(green, 0));


	libusb_alloc_transfer(0);
	   
//	printf("Buffer: %x\n", buffer);

	return 0;
}

/*

struct usb_dev_handle* get_green(struct usb_bus* bus, struct usb_device* dev){
	for(bus = usb_get_busses(); bus != NULL; bus = bus->next){
        for(dev = bus->devices; dev != NULL; dev = dev->next){
        	if(dev->descriptor.idVendor == VID && 
        		dev->descriptor.idProduct == PID){
        		printf("Returnning dev-handle");
        		return usb_open(dev);
        	}
		}
    }
    printf("Device not connected!\n");
    exit(1);
}


void printdev(struct usb_bus* bus, struct usb_device* dev){
    printf("bus/device idVendor/idProduct\n");
    for(bus = usb_get_busses(); bus != NULL; bus = bus->next){
        for(dev = bus->devices; dev != NULL; dev = dev->next){
            printf("%s/%s %04X/%04X\n", bus->dirname, dev->filename,
            dev->descriptor.idVendor, dev->descriptor.idProduct);
			udev = usb_open(dev);
           	if(udev){
        		if(dev->descriptor.iManufacturer){
         			int ret = usb_get_string_simple(
         			udev,dev->descriptor.iManufacturer, string, sizeof (string));
            		if(ret > 0)
           				printf("Manufacturer: %s\n", string);
            		else
                		printf("Unable to fetch manufacturer string\n");
                } else
                	printf("No manufacturer descriptor\n");
        	}
        	usb_close(udev);
    	}
    }
}

*/

        

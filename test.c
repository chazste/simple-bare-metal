
//volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;
volatile unsigned int * const UART1_URXD = (unsigned int *)0x02020000;
volatile unsigned int * const UART1_UTXD = (unsigned int *)0x02020040;
volatile unsigned int * const UART1_UCR1 = (unsigned int *)0x02020080;
volatile unsigned int * const UART1_UCR2 = (unsigned int *)0x02020084;
volatile unsigned int * const UART1_UCR3 = (unsigned int *)0x02020088;
volatile unsigned int * const UART1_UCR4 = (unsigned int *)0x0202008C;
volatile unsigned int * const UART1_UFCR = (unsigned int *)0x02020090;
volatile unsigned int * const UART1_USR1 = (unsigned int *)0x02020094;
volatile unsigned int * const UART1_USR2 = (unsigned int *)0x02020098;
volatile unsigned int * const UART1_UESC = (unsigned int *)0x0202009C;
volatile unsigned int * const UART1_UTIM = (unsigned int *)0x020200A0;
volatile unsigned int * const UART1_UBIR = (unsigned int *)0x020200A4;
volatile unsigned int * const UART1_UBMR = (unsigned int *)0x020200A8;
volatile unsigned int * const UART1_UBRC = (unsigned int *)0x020200AC;
volatile unsigned int * const UART1_ONEMS = (unsigned int *)0x020200B0;
volatile unsigned int * const UART1_UTS  = (unsigned int *)0x020200B4;
volatile unsigned int * const UART1_UMCR = (unsigned int *)0x020200B8;
 
void print_uart0(const char *s) 
{
	while(*s != '\0') /* Loop until end of string */
	{
		*UART1_UTXD = (unsigned int)(*s); /* Transmit char */
		s++; /* Next char */
	}
}
 
void c_entry() 
{
	/* from programmers guide */
	*UART1_UCR1 = 0x0001;
	*UART1_UCR2 = 0x2127;
	*UART1_UCR3 = 0x0704;
	*UART1_UCR4 = 0x7C00;
	*UART1_UFCR = 0x089E;
	*UART1_UBIR = 0x08FF;
	*UART1_UBMR = 0x0C34;
	*UART1_UCR1 = 0x2201;
	*UART1_UMCR = 0x0000;
	print_uart0("Hello world!\n");
}

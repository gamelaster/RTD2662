
#ifndef	__DEVOS_H__

#define	__DEVOS_H__

//#define	TRUE	(1)
//#define	FALSE	(0)
#define	ERROR	(-1)
#define	ENABLE	(1)
#define	DISABLE	(0)
#define	CLEAR	(0)
#define	_NULL	(0)

#define	BYTE	unsigned char
#define	WORD	unsigned short
#define	DWRD	unsigned long

#define	LPCTSTR	const char code*

typedef bit (code* _LPFNEVENTFUNC_)(void);
typedef bit (code* _LPFNEXCEPTION_)(LPCTSTR ErrMsg);
typedef	struct __COMMAND_KEY__
{
	LPCTSTR lpctszCommand;	// command key word.
	BYTE    MaxParams;	// maximum parameters.
	BYTE    MinParams;	// minimum parameters.
	LPCTSTR lpctszComment;	// command comment.
	
	_LPFNEVENTFUNC_ lpfnCmdFunc;
	_LPFNEXCEPTION_ lpfnGenExcp;
	
} COMMAND_KEY;

typedef bit (code* _LPFN_DIAGNOSTIC_TYPE_)(DWRD idata* lpdwAddrAry);
typedef	struct _DIAGNOSTIC_TYPE_
{
	LPCTSTR			lpctszType;	// command key word.
	_LPFN_DIAGNOSTIC_TYPE_	lpfnType;
	
} DIAGNOSTIC_TYPE;

typedef bit (code* _LPFN_ERASE_FLASHMEM_CMDTYPE_)(void);
typedef struct _ERASE_FLASHMEM_
{
	LPCTSTR				lpctszCmdType;
	_LPFN_ERASE_FLASHMEM_CMDTYPE_	lpfnCmdType;
	
} ERASE_FLASHMEM;

typedef const BYTE (code* _LPFN_PORTX_READ_ )(void);
typedef       void (code* _LPFN_PORTX_WRITE_)(const BYTE state);
typedef struct _PORTX_PROGRAMMING_
{
	LPCTSTR				lpctszPORTXname;
	_LPFN_PORTX_READ_		lpfnPORTXread;
	_LPFN_PORTX_WRITE_		lpfnPORTXwrite;
} PORTX_PROGRAMMING;

typedef const WORD (code* _LPFN_INTX_READ_ )(void);
typedef       void (code* _LPFN_INTX_WRITE_)(const WORD wData);
typedef struct _INTX_PROGRAMMING_
{
	LPCTSTR			lpctszINTKeyword;
	_LPFN_INTX_READ_	lpfnINTXread;
	_LPFN_INTX_WRITE_	lpfnINTXwrite;
	const WORD		wMask;
} INTX_PROGRAMMING;

#define	XADDR	0xE000
#define	XCS0	0xE000
#define	XCS1	0xE200
#define	XCS2	0xE400
#define	XCS3	0xE600
#define	FRESET	0xE800
#define	XALE0	0xEA00
#define	XALE1	0xEC00
#define	XALE2	0xEE00

#endif
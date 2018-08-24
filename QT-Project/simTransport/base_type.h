#ifndef SIMBASE_TYPE_H
#define SIMBASE_TYPE_H



/**
    \def TRUE
    Bool value true.
*/
#ifndef TRUE
#define	TRUE	(1)
#endif

/**
    \def FALSE
    Bool value false.
*/
#ifndef FALSE
#define FALSE	(0)
#endif

/**
    \def NULL
    Null pointer.
*/
#ifndef NULL
#define	NULL	((void *)0)
#endif

/**
    \def ARRAY_SIZE(a)
    Element total of array.
    \param[in] a : Array name.
*/
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)		(sizeof(a)/sizeof(a[0]))
#endif



/**
    \def ZERO
    ZERO value macro..
*/
#ifndef ZERO
#define ZERO 0          /**<define for '0'.*/
#endif
/*******************************************************************************
    Type Definition
*******************************************************************************/
/**
    \typedef unsigned char uint8
    Unsigned single byte integer type.
*/
typedef unsigned char		uint8;

/**
    \typedef signed char sint8
    Signed single byte integer type.
*/
typedef signed char			sint8;

/**
    \typedef unsigned short int uint16
    Unsigned double bytes integer type.
*/
typedef unsigned short int	uint16;

/**
    \typedef signed short int sint16
    Signed double bytes integer type.
*/
typedef signed short int	sint16;

/**
    \typedef unsigned int uint32
    Unsigned four bytes integer type.
*/
typedef unsigned int		uint32;

/**
    \typedef signed int sint32
    Signed four bytes integer type.
*/
typedef signed int			sint32;

/**
    \typedef unsigned long long	uint64
    Unsigned eight bytes integer type.
*/
typedef unsigned long long	uint64;

/**
    \typedef signed long long	sint64
    Signed eight bytes integer type.
*/
typedef signed long long	sint64;

/**
    \typedef float float32
    Single-precision float type.
*/
typedef float				float32;

/**
    \typedef double float64
    Double-precision float type.
*/
typedef double				float64;


/**
    \typedef char char_t
    Character type.
*/
typedef char				char_t;

/**
    \typedef int bool_t
    bool type.
*/
typedef int bool_t;

/**
    \typedef unsigned int ID
    ID type.
*/
typedef unsigned int		ID;

/**
     \enum sim_result_e
     callback result of function.
*/
typedef enum{
    SIM_SUCCESS ,                   /**<Success.                         */
    SIM_FAILURE,                    /**<False.                           */
}sim_result_e;


#endif // SIMBASE_TYPE_H



/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri May 01 10:54:02 2015
 */
/* Compiler settings for E:\Program Files\SQLite\sqlite-amalgamation-3080900\sqlite3.h:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __sqlite3_h_h__
#define __sqlite3_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_sqlite3_0000_0000 */
/* [local] */ 

#pragma once
#pragma once

#pragma pack(push, 8)
typedef unsigned int uintptr_t;

typedef unsigned char *va_list;


#pragma pack(pop)
extern const unsigned char sqlite3_version[  ];

const unsigned char *sqlite3_libversion( void);

const unsigned char *sqlite3_sourceid( void);

int sqlite3_libversion_number( void);

int sqlite3_compileoption_used( 
    const unsigned char *zOptName);

const unsigned char *sqlite3_compileoption_get( 
    int N);

int sqlite3_threadsafe( void);

typedef struct sqlite3 sqlite3;

typedef __int64 sqlite_int64;

typedef unsigned __int64 sqlite_uint64;

typedef sqlite_int64 sqlite3_int64;

typedef sqlite_uint64 sqlite3_uint64;

int sqlite3_close( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000000);

int sqlite3_close_v2( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000001);

typedef int ( *sqlite3_callback )( 
    void *__MIDL____MIDL_itf_sqlite3_0000_00000002,
    int __MIDL____MIDL_itf_sqlite3_0000_00000003,
    unsigned char **__MIDL____MIDL_itf_sqlite3_0000_00000004,
    unsigned char **__MIDL____MIDL_itf_sqlite3_0000_00000005);

int sqlite3_exec( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000007,
    const unsigned char *sql,
    int ( *callback )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000008,
        int __MIDL____MIDL_itf_sqlite3_0000_00000009,
        unsigned char **__MIDL____MIDL_itf_sqlite3_0000_00000010,
        unsigned char **__MIDL____MIDL_itf_sqlite3_0000_00000011),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000013,
    unsigned char **errmsg);

typedef struct sqlite3_file sqlite3_file;

struct sqlite3_file
    {
    const struct sqlite3_io_methods *pMethods;
    } ;
typedef struct sqlite3_io_methods sqlite3_io_methods;

struct sqlite3_io_methods
    {
    int iVersion;
    int ( *xClose )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000014);
    int ( *xRead )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000016,
        void *__MIDL____MIDL_itf_sqlite3_0000_00000017,
        int iAmt,
        sqlite3_int64 iOfst);
    int ( *xWrite )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000019,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000020,
        int iAmt,
        sqlite3_int64 iOfst);
    int ( *xTruncate )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000022,
        sqlite3_int64 size);
    int ( *xSync )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000024,
        int flags);
    int ( *xFileSize )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000026,
        sqlite3_int64 *pSize);
    int ( *xLock )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000028,
        int __MIDL____MIDL_itf_sqlite3_0000_00000029);
    int ( *xUnlock )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000031,
        int __MIDL____MIDL_itf_sqlite3_0000_00000032);
    int ( *xCheckReservedLock )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000034,
        int *pResOut);
    int ( *xFileControl )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000036,
        int op,
        void *pArg);
    int ( *xSectorSize )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000038);
    int ( *xDeviceCharacteristics )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000040);
    int ( *xShmMap )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000042,
        int iPg,
        int pgsz,
        int __MIDL____MIDL_itf_sqlite3_0000_00000043,
        volatile void **__MIDL____MIDL_itf_sqlite3_0000_00000044);
    int ( *xShmLock )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000046,
        int offset,
        int n,
        int flags);
    void ( *xShmBarrier )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000048);
    int ( *xShmUnmap )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000050,
        int deleteFlag);
    int ( *xFetch )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000052,
        sqlite3_int64 iOfst,
        int iAmt,
        void **pp);
    int ( *xUnfetch )( 
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000054,
        sqlite3_int64 iOfst,
        void *p);
    } ;
typedef struct sqlite3_mutex sqlite3_mutex;

typedef struct sqlite3_vfs sqlite3_vfs;

typedef void ( *sqlite3_syscall_ptr )( void);

struct sqlite3_vfs
    {
    int iVersion;
    int szOsFile;
    int mxPathname;
    sqlite3_vfs *pNext;
    const unsigned char *zName;
    void *pAppData;
    int ( *xOpen )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000057,
        const unsigned char *zName,
        sqlite3_file *__MIDL____MIDL_itf_sqlite3_0000_00000058,
        int flags,
        int *pOutFlags);
    int ( *xDelete )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000060,
        const unsigned char *zName,
        int syncDir);
    int ( *xAccess )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000062,
        const unsigned char *zName,
        int flags,
        int *pResOut);
    int ( *xFullPathname )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000064,
        const unsigned char *zName,
        int nOut,
        unsigned char *zOut);
    void *( *xDlOpen )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000066,
        const unsigned char *zFilename);
    void ( *xDlError )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000068,
        int nByte,
        unsigned char *zErrMsg);
    void ( *( *xDlSym ) )( void)( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000070,
        void *__MIDL____MIDL_itf_sqlite3_0000_00000071,
        const unsigned char *zSymbol);
    void ( *xDlClose )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000074,
        void *__MIDL____MIDL_itf_sqlite3_0000_00000075);
    int ( *xRandomness )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000077,
        int nByte,
        unsigned char *zOut);
    int ( *xSleep )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000079,
        int microseconds);
    int ( *xCurrentTime )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000081,
        double *__MIDL____MIDL_itf_sqlite3_0000_00000082);
    int ( *xGetLastError )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000084,
        int __MIDL____MIDL_itf_sqlite3_0000_00000085,
        unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000086);
    int ( *xCurrentTimeInt64 )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000088,
        sqlite3_int64 *__MIDL____MIDL_itf_sqlite3_0000_00000089);
    int ( *xSetSystemCall )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000091,
        const unsigned char *zName,
        sqlite3_syscall_ptr __MIDL____MIDL_itf_sqlite3_0000_00000092);
    sqlite3_syscall_ptr ( *xGetSystemCall )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000094,
        const unsigned char *zName);
    const unsigned char *( *xNextSystemCall )( 
        sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000096,
        const unsigned char *zName);
    } ;
int sqlite3_initialize( void);

int sqlite3_shutdown( void);

int sqlite3_os_init( void);

int sqlite3_os_end( void);

int sqlite3_config( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000098,
    ...);

int sqlite3_db_config( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000099,
    int op,
    ...);

typedef struct sqlite3_mem_methods sqlite3_mem_methods;

struct sqlite3_mem_methods
    {
    void *( *xMalloc )( 
        int __MIDL____MIDL_itf_sqlite3_0000_00000100);
    void ( *xFree )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000102);
    void *( *xRealloc )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000104,
        int __MIDL____MIDL_itf_sqlite3_0000_00000105);
    int ( *xSize )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000107);
    int ( *xRoundup )( 
        int __MIDL____MIDL_itf_sqlite3_0000_00000109);
    int ( *xInit )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000111);
    void ( *xShutdown )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000113);
    void *pAppData;
    } ;
int sqlite3_extended_result_codes( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000115,
    int onoff);

sqlite3_int64 sqlite3_last_insert_rowid( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000116);

int sqlite3_changes( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000117);

int sqlite3_total_changes( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000118);

void sqlite3_interrupt( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000119);

int sqlite3_complete( 
    const unsigned char *sql);

int sqlite3_complete16( 
    const void *sql);

int sqlite3_busy_handler( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000120,
    int ( *__MIDL____MIDL_itf_sqlite3_0000_00000124 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000121,
        int __MIDL____MIDL_itf_sqlite3_0000_00000122),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000125);

int sqlite3_busy_timeout( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000126,
    int ms);

int sqlite3_get_table( 
    sqlite3 *db,
    const unsigned char *zSql,
    unsigned char ***pazResult,
    int *pnRow,
    int *pnColumn,
    unsigned char **pzErrmsg);

void sqlite3_free_table( 
    unsigned char **result);

unsigned char *sqlite3_mprintf( 
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000127,
    ...);

unsigned char *sqlite3_vmprintf( 
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000128,
    va_list __MIDL____MIDL_itf_sqlite3_0000_00000129);

unsigned char *sqlite3_snprintf( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000130,
    unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000131,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000132,
    ...);

unsigned char *sqlite3_vsnprintf( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000133,
    unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000134,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000135,
    va_list __MIDL____MIDL_itf_sqlite3_0000_00000136);

void *sqlite3_malloc( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000137);

void *sqlite3_malloc64( 
    sqlite3_uint64 __MIDL____MIDL_itf_sqlite3_0000_00000138);

void *sqlite3_realloc( 
    void *__MIDL____MIDL_itf_sqlite3_0000_00000139,
    int __MIDL____MIDL_itf_sqlite3_0000_00000140);

void *sqlite3_realloc64( 
    void *__MIDL____MIDL_itf_sqlite3_0000_00000141,
    sqlite3_uint64 __MIDL____MIDL_itf_sqlite3_0000_00000142);

void sqlite3_free( 
    void *__MIDL____MIDL_itf_sqlite3_0000_00000143);

sqlite3_uint64 sqlite3_msize( 
    void *__MIDL____MIDL_itf_sqlite3_0000_00000144);

sqlite3_int64 sqlite3_memory_used( void);

sqlite3_int64 sqlite3_memory_highwater( 
    int resetFlag);

void sqlite3_randomness( 
    int N,
    void *P);

int sqlite3_set_authorizer( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000145,
    int ( *xAuth )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000146,
        int __MIDL____MIDL_itf_sqlite3_0000_00000147,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000148,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000149,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000150,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000151),
    void *pUserData);

void *sqlite3_trace( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000153,
    void ( *xTrace )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000154,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000155),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000157);

void *sqlite3_profile( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000158,
    void ( *xProfile )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000159,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000160,
        sqlite3_uint64 __MIDL____MIDL_itf_sqlite3_0000_00000161),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000163);

void sqlite3_progress_handler( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000164,
    int __MIDL____MIDL_itf_sqlite3_0000_00000165,
    int ( *__MIDL____MIDL_itf_sqlite3_0000_00000168 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000166),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000169);

int sqlite3_open( 
    const unsigned char *filename,
    sqlite3 **ppDb);

int sqlite3_open16( 
    const void *filename,
    sqlite3 **ppDb);

int sqlite3_open_v2( 
    const unsigned char *filename,
    sqlite3 **ppDb,
    int flags,
    const unsigned char *zVfs);

const unsigned char *sqlite3_uri_parameter( 
    const unsigned char *zFilename,
    const unsigned char *zParam);

int sqlite3_uri_boolean( 
    const unsigned char *zFile,
    const unsigned char *zParam,
    int bDefault);

sqlite3_int64 sqlite3_uri_int64( 
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000170,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000171,
    sqlite3_int64 __MIDL____MIDL_itf_sqlite3_0000_00000172);

int sqlite3_errcode( 
    sqlite3 *db);

int sqlite3_extended_errcode( 
    sqlite3 *db);

const unsigned char *sqlite3_errmsg( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000173);

const void *sqlite3_errmsg16( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000174);

const unsigned char *sqlite3_errstr( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000175);

typedef struct sqlite3_stmt sqlite3_stmt;

int sqlite3_limit( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000176,
    int id,
    int newVal);

int sqlite3_prepare( 
    sqlite3 *db,
    const unsigned char *zSql,
    int nByte,
    sqlite3_stmt **ppStmt,
    const unsigned char **pzTail);

int sqlite3_prepare_v2( 
    sqlite3 *db,
    const unsigned char *zSql,
    int nByte,
    sqlite3_stmt **ppStmt,
    const unsigned char **pzTail);

int sqlite3_prepare16( 
    sqlite3 *db,
    const void *zSql,
    int nByte,
    sqlite3_stmt **ppStmt,
    const void **pzTail);

int sqlite3_prepare16_v2( 
    sqlite3 *db,
    const void *zSql,
    int nByte,
    sqlite3_stmt **ppStmt,
    const void **pzTail);

const unsigned char *sqlite3_sql( 
    sqlite3_stmt *pStmt);

int sqlite3_stmt_readonly( 
    sqlite3_stmt *pStmt);

int sqlite3_stmt_busy( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000177);

typedef struct Mem sqlite3_value;

typedef struct sqlite3_context sqlite3_context;

int sqlite3_bind_blob( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000178,
    int __MIDL____MIDL_itf_sqlite3_0000_00000179,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000180,
    int n,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000183 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000181));

int sqlite3_bind_blob64( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000184,
    int __MIDL____MIDL_itf_sqlite3_0000_00000185,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000186,
    sqlite3_uint64 __MIDL____MIDL_itf_sqlite3_0000_00000187,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000190 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000188));

int sqlite3_bind_double( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000191,
    int __MIDL____MIDL_itf_sqlite3_0000_00000192,
    double __MIDL____MIDL_itf_sqlite3_0000_00000193);

int sqlite3_bind_int( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000194,
    int __MIDL____MIDL_itf_sqlite3_0000_00000195,
    int __MIDL____MIDL_itf_sqlite3_0000_00000196);

int sqlite3_bind_int64( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000197,
    int __MIDL____MIDL_itf_sqlite3_0000_00000198,
    sqlite3_int64 __MIDL____MIDL_itf_sqlite3_0000_00000199);

int sqlite3_bind_null( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000200,
    int __MIDL____MIDL_itf_sqlite3_0000_00000201);

int sqlite3_bind_text( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000202,
    int __MIDL____MIDL_itf_sqlite3_0000_00000203,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000204,
    int __MIDL____MIDL_itf_sqlite3_0000_00000205,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000208 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000206));

int sqlite3_bind_text16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000209,
    int __MIDL____MIDL_itf_sqlite3_0000_00000210,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000211,
    int __MIDL____MIDL_itf_sqlite3_0000_00000212,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000215 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000213));

int sqlite3_bind_text64( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000216,
    int __MIDL____MIDL_itf_sqlite3_0000_00000217,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000218,
    sqlite3_uint64 __MIDL____MIDL_itf_sqlite3_0000_00000219,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000222 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000220),
    unsigned char encoding);

int sqlite3_bind_value( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000223,
    int __MIDL____MIDL_itf_sqlite3_0000_00000224,
    const sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000225);

int sqlite3_bind_zeroblob( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000226,
    int __MIDL____MIDL_itf_sqlite3_0000_00000227,
    int n);

int sqlite3_bind_parameter_count( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000228);

const unsigned char *sqlite3_bind_parameter_name( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000229,
    int __MIDL____MIDL_itf_sqlite3_0000_00000230);

int sqlite3_bind_parameter_index( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000231,
    const unsigned char *zName);

int sqlite3_clear_bindings( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000232);

int sqlite3_column_count( 
    sqlite3_stmt *pStmt);

const unsigned char *sqlite3_column_name( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000233,
    int N);

const void *sqlite3_column_name16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000234,
    int N);

const unsigned char *sqlite3_column_database_name( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000235,
    int __MIDL____MIDL_itf_sqlite3_0000_00000236);

const void *sqlite3_column_database_name16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000237,
    int __MIDL____MIDL_itf_sqlite3_0000_00000238);

const unsigned char *sqlite3_column_table_name( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000239,
    int __MIDL____MIDL_itf_sqlite3_0000_00000240);

const void *sqlite3_column_table_name16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000241,
    int __MIDL____MIDL_itf_sqlite3_0000_00000242);

const unsigned char *sqlite3_column_origin_name( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000243,
    int __MIDL____MIDL_itf_sqlite3_0000_00000244);

const void *sqlite3_column_origin_name16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000245,
    int __MIDL____MIDL_itf_sqlite3_0000_00000246);

const unsigned char *sqlite3_column_decltype( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000247,
    int __MIDL____MIDL_itf_sqlite3_0000_00000248);

const void *sqlite3_column_decltype16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000249,
    int __MIDL____MIDL_itf_sqlite3_0000_00000250);

int sqlite3_step( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000251);

int sqlite3_data_count( 
    sqlite3_stmt *pStmt);

const void *sqlite3_column_blob( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000252,
    int iCol);

int sqlite3_column_bytes( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000253,
    int iCol);

int sqlite3_column_bytes16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000254,
    int iCol);

double sqlite3_column_double( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000255,
    int iCol);

int sqlite3_column_int( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000256,
    int iCol);

sqlite3_int64 sqlite3_column_int64( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000257,
    int iCol);

const unsigned char *sqlite3_column_text( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000258,
    int iCol);

const void *sqlite3_column_text16( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000259,
    int iCol);

int sqlite3_column_type( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000260,
    int iCol);

sqlite3_value *sqlite3_column_value( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000261,
    int iCol);

int sqlite3_finalize( 
    sqlite3_stmt *pStmt);

int sqlite3_reset( 
    sqlite3_stmt *pStmt);

int sqlite3_create_function( 
    sqlite3 *db,
    const unsigned char *zFunctionName,
    int nArg,
    int eTextRep,
    void *pApp,
    void ( *xFunc )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000262,
        int __MIDL____MIDL_itf_sqlite3_0000_00000263,
        sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000264),
    void ( *xStep )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000266,
        int __MIDL____MIDL_itf_sqlite3_0000_00000267,
        sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000268),
    void ( *xFinal )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000270));

int sqlite3_create_function16( 
    sqlite3 *db,
    const void *zFunctionName,
    int nArg,
    int eTextRep,
    void *pApp,
    void ( *xFunc )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000272,
        int __MIDL____MIDL_itf_sqlite3_0000_00000273,
        sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000274),
    void ( *xStep )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000276,
        int __MIDL____MIDL_itf_sqlite3_0000_00000277,
        sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000278),
    void ( *xFinal )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000280));

int sqlite3_create_function_v2( 
    sqlite3 *db,
    const unsigned char *zFunctionName,
    int nArg,
    int eTextRep,
    void *pApp,
    void ( *xFunc )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000282,
        int __MIDL____MIDL_itf_sqlite3_0000_00000283,
        sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000284),
    void ( *xStep )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000286,
        int __MIDL____MIDL_itf_sqlite3_0000_00000287,
        sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000288),
    void ( *xFinal )( 
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000290),
    void ( *xDestroy )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000292));

int sqlite3_aggregate_count( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000294);

int sqlite3_expired( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000295);

int sqlite3_transfer_bindings( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000296,
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000297);

int sqlite3_global_recover( void);

void sqlite3_thread_cleanup( void);

int sqlite3_memory_alarm( 
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000302 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000298,
        sqlite3_int64 __MIDL____MIDL_itf_sqlite3_0000_00000299,
        int __MIDL____MIDL_itf_sqlite3_0000_00000300),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000303,
    sqlite3_int64 __MIDL____MIDL_itf_sqlite3_0000_00000304);

const void *sqlite3_value_blob( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000305);

int sqlite3_value_bytes( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000306);

int sqlite3_value_bytes16( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000307);

double sqlite3_value_double( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000308);

int sqlite3_value_int( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000309);

sqlite3_int64 sqlite3_value_int64( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000310);

const unsigned char *sqlite3_value_text( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000311);

const void *sqlite3_value_text16( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000312);

const void *sqlite3_value_text16le( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000313);

const void *sqlite3_value_text16be( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000314);

int sqlite3_value_type( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000315);

int sqlite3_value_numeric_type( 
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000316);

void *sqlite3_aggregate_context( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000317,
    int nBytes);

void *sqlite3_user_data( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000318);

sqlite3 *sqlite3_context_db_handle( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000319);

void *sqlite3_get_auxdata( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000320,
    int N);

void sqlite3_set_auxdata( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000321,
    int N,
    void *__MIDL____MIDL_itf_sqlite3_0000_00000322,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000325 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000323));

typedef void ( *sqlite3_destructor_type )( 
    void *__MIDL____MIDL_itf_sqlite3_0000_00000326);

void sqlite3_result_blob( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000328,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000329,
    int __MIDL____MIDL_itf_sqlite3_0000_00000330,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000333 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000331));

void sqlite3_result_blob64( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000334,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000335,
    sqlite3_uint64 __MIDL____MIDL_itf_sqlite3_0000_00000336,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000339 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000337));

void sqlite3_result_double( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000340,
    double __MIDL____MIDL_itf_sqlite3_0000_00000341);

void sqlite3_result_error( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000342,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000343,
    int __MIDL____MIDL_itf_sqlite3_0000_00000344);

void sqlite3_result_error16( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000345,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000346,
    int __MIDL____MIDL_itf_sqlite3_0000_00000347);

void sqlite3_result_error_toobig( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000348);

void sqlite3_result_error_nomem( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000349);

void sqlite3_result_error_code( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000350,
    int __MIDL____MIDL_itf_sqlite3_0000_00000351);

void sqlite3_result_int( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000352,
    int __MIDL____MIDL_itf_sqlite3_0000_00000353);

void sqlite3_result_int64( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000354,
    sqlite3_int64 __MIDL____MIDL_itf_sqlite3_0000_00000355);

void sqlite3_result_null( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000356);

void sqlite3_result_text( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000357,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000358,
    int __MIDL____MIDL_itf_sqlite3_0000_00000359,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000362 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000360));

void sqlite3_result_text64( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000363,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000364,
    sqlite3_uint64 __MIDL____MIDL_itf_sqlite3_0000_00000365,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000368 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000366),
    unsigned char encoding);

void sqlite3_result_text16( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000369,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000370,
    int __MIDL____MIDL_itf_sqlite3_0000_00000371,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000374 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000372));

void sqlite3_result_text16le( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000375,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000376,
    int __MIDL____MIDL_itf_sqlite3_0000_00000377,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000380 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000378));

void sqlite3_result_text16be( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000381,
    const void *__MIDL____MIDL_itf_sqlite3_0000_00000382,
    int __MIDL____MIDL_itf_sqlite3_0000_00000383,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000386 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000384));

void sqlite3_result_value( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000387,
    sqlite3_value *__MIDL____MIDL_itf_sqlite3_0000_00000388);

void sqlite3_result_zeroblob( 
    sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000389,
    int n);

int sqlite3_create_collation( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000390,
    const unsigned char *zName,
    int eTextRep,
    void *pArg,
    int ( *xCompare )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000391,
        int __MIDL____MIDL_itf_sqlite3_0000_00000392,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000393,
        int __MIDL____MIDL_itf_sqlite3_0000_00000394,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000395));

int sqlite3_create_collation_v2( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000397,
    const unsigned char *zName,
    int eTextRep,
    void *pArg,
    int ( *xCompare )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000398,
        int __MIDL____MIDL_itf_sqlite3_0000_00000399,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000400,
        int __MIDL____MIDL_itf_sqlite3_0000_00000401,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000402),
    void ( *xDestroy )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000404));

int sqlite3_create_collation16( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000406,
    const void *zName,
    int eTextRep,
    void *pArg,
    int ( *xCompare )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000407,
        int __MIDL____MIDL_itf_sqlite3_0000_00000408,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000409,
        int __MIDL____MIDL_itf_sqlite3_0000_00000410,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000411));

int sqlite3_collation_needed( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000413,
    void *__MIDL____MIDL_itf_sqlite3_0000_00000414,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000419 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000415,
        sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000416,
        int eTextRep,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000417));

int sqlite3_collation_needed16( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000420,
    void *__MIDL____MIDL_itf_sqlite3_0000_00000421,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000426 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000422,
        sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000423,
        int eTextRep,
        const void *__MIDL____MIDL_itf_sqlite3_0000_00000424));

int sqlite3_sleep( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000427);

extern unsigned char *sqlite3_temp_directory;

extern unsigned char *sqlite3_data_directory;

int sqlite3_get_autocommit( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000428);

sqlite3 *sqlite3_db_handle( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000429);

const unsigned char *sqlite3_db_filename( 
    sqlite3 *db,
    const unsigned char *zDbName);

int sqlite3_db_readonly( 
    sqlite3 *db,
    const unsigned char *zDbName);

sqlite3_stmt *sqlite3_next_stmt( 
    sqlite3 *pDb,
    sqlite3_stmt *pStmt);

void *sqlite3_commit_hook( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000430,
    int ( *__MIDL____MIDL_itf_sqlite3_0000_00000433 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000431),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000434);

void *sqlite3_rollback_hook( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000435,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000438 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000436),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000439);

void *sqlite3_update_hook( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000440,
    void ( *__MIDL____MIDL_itf_sqlite3_0000_00000447 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000441,
        int __MIDL____MIDL_itf_sqlite3_0000_00000442,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000443,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000444,
        sqlite3_int64 __MIDL____MIDL_itf_sqlite3_0000_00000445),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000448);

int sqlite3_enable_shared_cache( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000449);

int sqlite3_release_memory( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000450);

int sqlite3_db_release_memory( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000451);

sqlite3_int64 sqlite3_soft_heap_limit64( 
    sqlite3_int64 N);

void sqlite3_soft_heap_limit( 
    int N);

int sqlite3_table_column_metadata( 
    sqlite3 *db,
    const unsigned char *zDbName,
    const unsigned char *zTableName,
    const unsigned char *zColumnName,
    const unsigned char **pzDataType,
    const unsigned char **pzCollSeq,
    int *pNotNull,
    int *pPrimaryKey,
    int *pAutoinc);

int sqlite3_load_extension( 
    sqlite3 *db,
    const unsigned char *zFile,
    const unsigned char *zProc,
    unsigned char **pzErrMsg);

int sqlite3_enable_load_extension( 
    sqlite3 *db,
    int onoff);

int sqlite3_auto_extension( 
    void ( *xEntryPoint )( void));

int sqlite3_cancel_auto_extension( 
    void ( *xEntryPoint )( void));

void sqlite3_reset_auto_extension( void);

typedef struct sqlite3_vtab sqlite3_vtab;

typedef struct sqlite3_index_info sqlite3_index_info;

typedef struct sqlite3_vtab_cursor sqlite3_vtab_cursor;

typedef struct sqlite3_module sqlite3_module;

struct sqlite3_module
    {
    int iVersion;
    int ( *xCreate )( 
        sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000454,
        void *pAux,
        int argc,
        const unsigned char *const *argv,
        sqlite3_vtab **ppVTab,
        unsigned char **__MIDL____MIDL_itf_sqlite3_0000_00000455);
    int ( *xConnect )( 
        sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000457,
        void *pAux,
        int argc,
        const unsigned char *const *argv,
        sqlite3_vtab **ppVTab,
        unsigned char **__MIDL____MIDL_itf_sqlite3_0000_00000458);
    int ( *xBestIndex )( 
        sqlite3_vtab *pVTab,
        sqlite3_index_info *__MIDL____MIDL_itf_sqlite3_0000_00000460);
    int ( *xDisconnect )( 
        sqlite3_vtab *pVTab);
    int ( *xDestroy )( 
        sqlite3_vtab *pVTab);
    int ( *xOpen )( 
        sqlite3_vtab *pVTab,
        sqlite3_vtab_cursor **ppCursor);
    int ( *xClose )( 
        sqlite3_vtab_cursor *__MIDL____MIDL_itf_sqlite3_0000_00000465);
    int ( *xFilter )( 
        sqlite3_vtab_cursor *__MIDL____MIDL_itf_sqlite3_0000_00000467,
        int idxNum,
        const unsigned char *idxStr,
        int argc,
        sqlite3_value **argv);
    int ( *xNext )( 
        sqlite3_vtab_cursor *__MIDL____MIDL_itf_sqlite3_0000_00000469);
    int ( *xEof )( 
        sqlite3_vtab_cursor *__MIDL____MIDL_itf_sqlite3_0000_00000471);
    int ( *xColumn )( 
        sqlite3_vtab_cursor *__MIDL____MIDL_itf_sqlite3_0000_00000473,
        sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000474,
        int __MIDL____MIDL_itf_sqlite3_0000_00000475);
    int ( *xRowid )( 
        sqlite3_vtab_cursor *__MIDL____MIDL_itf_sqlite3_0000_00000477,
        sqlite3_int64 *pRowid);
    int ( *xUpdate )( 
        sqlite3_vtab *__MIDL____MIDL_itf_sqlite3_0000_00000479,
        int __MIDL____MIDL_itf_sqlite3_0000_00000480,
        sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000481,
        sqlite3_int64 *__MIDL____MIDL_itf_sqlite3_0000_00000482);
    int ( *xBegin )( 
        sqlite3_vtab *pVTab);
    int ( *xSync )( 
        sqlite3_vtab *pVTab);
    int ( *xCommit )( 
        sqlite3_vtab *pVTab);
    int ( *xRollback )( 
        sqlite3_vtab *pVTab);
    int ( *xFindFunction )( 
        sqlite3_vtab *pVtab,
        int nArg,
        const unsigned char *zName,
        void ( **pxFunc )( 
            sqlite3_context *__MIDL____MIDL_itf_sqlite3_0000_00000488,
            int __MIDL____MIDL_itf_sqlite3_0000_00000489,
            sqlite3_value **__MIDL____MIDL_itf_sqlite3_0000_00000490),
        void **ppArg);
    int ( *xRename )( 
        sqlite3_vtab *pVtab,
        const unsigned char *zNew);
    int ( *xSavepoint )( 
        sqlite3_vtab *pVTab,
        int __MIDL____MIDL_itf_sqlite3_0000_00000494);
    int ( *xRelease )( 
        sqlite3_vtab *pVTab,
        int __MIDL____MIDL_itf_sqlite3_0000_00000496);
    int ( *xRollbackTo )( 
        sqlite3_vtab *pVTab,
        int __MIDL____MIDL_itf_sqlite3_0000_00000498);
    } ;
struct sqlite3_index_info
    {
    int nConstraint;
    struct sqlite3_index_constraint
        {
        int iColumn;
        unsigned char op;
        unsigned char usable;
        int iTermOffset;
        } 	*aConstraint;
    int nOrderBy;
    struct sqlite3_index_orderby
        {
        int iColumn;
        unsigned char desc;
        } 	*aOrderBy;
    struct sqlite3_index_constraint_usage
        {
        int argvIndex;
        unsigned char omit;
        } 	*aConstraintUsage;
    int idxNum;
    unsigned char *idxStr;
    int needToFreeIdxStr;
    int orderByConsumed;
    double estimatedCost;
    sqlite3_int64 estimatedRows;
    } ;
int sqlite3_create_module( 
    sqlite3 *db,
    const unsigned char *zName,
    const sqlite3_module *p,
    void *pClientData);

int sqlite3_create_module_v2( 
    sqlite3 *db,
    const unsigned char *zName,
    const sqlite3_module *p,
    void *pClientData,
    void ( *xDestroy )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000500));

struct sqlite3_vtab
    {
    const sqlite3_module *pModule;
    int nRef;
    unsigned char *zErrMsg;
    } ;
struct sqlite3_vtab_cursor
    {
    sqlite3_vtab *pVtab;
    } ;
int sqlite3_declare_vtab( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000502,
    const unsigned char *zSQL);

int sqlite3_overload_function( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000503,
    const unsigned char *zFuncName,
    int nArg);

typedef struct sqlite3_blob sqlite3_blob;

int sqlite3_blob_open( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000504,
    const unsigned char *zDb,
    const unsigned char *zTable,
    const unsigned char *zColumn,
    sqlite3_int64 iRow,
    int flags,
    sqlite3_blob **ppBlob);

int sqlite3_blob_reopen( 
    sqlite3_blob *__MIDL____MIDL_itf_sqlite3_0000_00000505,
    sqlite3_int64 __MIDL____MIDL_itf_sqlite3_0000_00000506);

int sqlite3_blob_close( 
    sqlite3_blob *__MIDL____MIDL_itf_sqlite3_0000_00000507);

int sqlite3_blob_bytes( 
    sqlite3_blob *__MIDL____MIDL_itf_sqlite3_0000_00000508);

int sqlite3_blob_read( 
    sqlite3_blob *__MIDL____MIDL_itf_sqlite3_0000_00000509,
    void *Z,
    int N,
    int iOffset);

int sqlite3_blob_write( 
    sqlite3_blob *__MIDL____MIDL_itf_sqlite3_0000_00000510,
    const void *z,
    int n,
    int iOffset);

sqlite3_vfs *sqlite3_vfs_find( 
    const unsigned char *zVfsName);

int sqlite3_vfs_register( 
    sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000511,
    int makeDflt);

int sqlite3_vfs_unregister( 
    sqlite3_vfs *__MIDL____MIDL_itf_sqlite3_0000_00000512);

sqlite3_mutex *sqlite3_mutex_alloc( 
    int __MIDL____MIDL_itf_sqlite3_0000_00000513);

void sqlite3_mutex_free( 
    sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000514);

void sqlite3_mutex_enter( 
    sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000515);

int sqlite3_mutex_try( 
    sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000516);

void sqlite3_mutex_leave( 
    sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000517);

typedef struct sqlite3_mutex_methods sqlite3_mutex_methods;

struct sqlite3_mutex_methods
    {
    int ( *xMutexInit )( void);
    int ( *xMutexEnd )( void);
    sqlite3_mutex *( *xMutexAlloc )( 
        int __MIDL____MIDL_itf_sqlite3_0000_00000520);
    void ( *xMutexFree )( 
        sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000522);
    void ( *xMutexEnter )( 
        sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000524);
    int ( *xMutexTry )( 
        sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000526);
    void ( *xMutexLeave )( 
        sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000528);
    int ( *xMutexHeld )( 
        sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000530);
    int ( *xMutexNotheld )( 
        sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000532);
    } ;
int sqlite3_mutex_held( 
    sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000534);

int sqlite3_mutex_notheld( 
    sqlite3_mutex *__MIDL____MIDL_itf_sqlite3_0000_00000535);

sqlite3_mutex *sqlite3_db_mutex( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000536);

int sqlite3_file_control( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000537,
    const unsigned char *zDbName,
    int op,
    void *__MIDL____MIDL_itf_sqlite3_0000_00000538);

int sqlite3_test_control( 
    int op,
    ...);

int sqlite3_status( 
    int op,
    int *pCurrent,
    int *pHighwater,
    int resetFlag);

int sqlite3_status64( 
    int op,
    sqlite3_int64 *pCurrent,
    sqlite3_int64 *pHighwater,
    int resetFlag);

int sqlite3_db_status( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000539,
    int op,
    int *pCur,
    int *pHiwtr,
    int resetFlg);

int sqlite3_stmt_status( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000540,
    int op,
    int resetFlg);

typedef struct sqlite3_pcache sqlite3_pcache;

typedef struct sqlite3_pcache_page sqlite3_pcache_page;

struct sqlite3_pcache_page
    {
    void *pBuf;
    void *pExtra;
    } ;
typedef struct sqlite3_pcache_methods2 sqlite3_pcache_methods2;

struct sqlite3_pcache_methods2
    {
    int iVersion;
    void *pArg;
    int ( *xInit )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000541);
    void ( *xShutdown )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000543);
    sqlite3_pcache *( *xCreate )( 
        int szPage,
        int szExtra,
        int bPurgeable);
    void ( *xCachesize )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000546,
        int nCachesize);
    int ( *xPagecount )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000548);
    sqlite3_pcache_page *( *xFetch )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000550,
        unsigned int key,
        int createFlag);
    void ( *xUnpin )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000552,
        sqlite3_pcache_page *__MIDL____MIDL_itf_sqlite3_0000_00000553,
        int discard);
    void ( *xRekey )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000555,
        sqlite3_pcache_page *__MIDL____MIDL_itf_sqlite3_0000_00000556,
        unsigned int oldKey,
        unsigned int newKey);
    void ( *xTruncate )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000558,
        unsigned int iLimit);
    void ( *xDestroy )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000560);
    void ( *xShrink )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000562);
    } ;
typedef struct sqlite3_pcache_methods sqlite3_pcache_methods;

struct sqlite3_pcache_methods
    {
    void *pArg;
    int ( *xInit )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000564);
    void ( *xShutdown )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000566);
    sqlite3_pcache *( *xCreate )( 
        int szPage,
        int bPurgeable);
    void ( *xCachesize )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000569,
        int nCachesize);
    int ( *xPagecount )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000571);
    void *( *xFetch )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000573,
        unsigned int key,
        int createFlag);
    void ( *xUnpin )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000575,
        void *__MIDL____MIDL_itf_sqlite3_0000_00000576,
        int discard);
    void ( *xRekey )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000578,
        void *__MIDL____MIDL_itf_sqlite3_0000_00000579,
        unsigned int oldKey,
        unsigned int newKey);
    void ( *xTruncate )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000581,
        unsigned int iLimit);
    void ( *xDestroy )( 
        sqlite3_pcache *__MIDL____MIDL_itf_sqlite3_0000_00000583);
    } ;
typedef struct sqlite3_backup sqlite3_backup;

sqlite3_backup *sqlite3_backup_init( 
    sqlite3 *pDest,
    const unsigned char *zDestName,
    sqlite3 *pSource,
    const unsigned char *zSourceName);

int sqlite3_backup_step( 
    sqlite3_backup *p,
    int nPage);

int sqlite3_backup_finish( 
    sqlite3_backup *p);

int sqlite3_backup_remaining( 
    sqlite3_backup *p);

int sqlite3_backup_pagecount( 
    sqlite3_backup *p);

int sqlite3_unlock_notify( 
    sqlite3 *pBlocked,
    void ( *xNotify )( 
        void **apArg,
        int nArg),
    void *pNotifyArg);

int sqlite3_stricmp( 
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000586,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000587);

int sqlite3_strnicmp( 
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000588,
    const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000589,
    int __MIDL____MIDL_itf_sqlite3_0000_00000590);

int sqlite3_strglob( 
    const unsigned char *zGlob,
    const unsigned char *zStr);

void sqlite3_log( 
    int iErrCode,
    const unsigned char *zFormat,
    ...);

void *sqlite3_wal_hook( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000591,
    int ( *__MIDL____MIDL_itf_sqlite3_0000_00000597 )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000592,
        sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000593,
        const unsigned char *__MIDL____MIDL_itf_sqlite3_0000_00000594,
        int __MIDL____MIDL_itf_sqlite3_0000_00000595),
    void *__MIDL____MIDL_itf_sqlite3_0000_00000598);

int sqlite3_wal_autocheckpoint( 
    sqlite3 *db,
    int N);

int sqlite3_wal_checkpoint( 
    sqlite3 *db,
    const unsigned char *zDb);

int sqlite3_wal_checkpoint_v2( 
    sqlite3 *db,
    const unsigned char *zDb,
    int eMode,
    int *pnLog,
    int *pnCkpt);

int sqlite3_vtab_config( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000599,
    int op,
    ...);

int sqlite3_vtab_on_conflict( 
    sqlite3 *__MIDL____MIDL_itf_sqlite3_0000_00000600);

int sqlite3_stmt_scanstatus( 
    sqlite3_stmt *pStmt,
    int idx,
    int iScanStatusOp,
    void *pOut);

void sqlite3_stmt_scanstatus_reset( 
    sqlite3_stmt *__MIDL____MIDL_itf_sqlite3_0000_00000601);

typedef struct sqlite3_rtree_geometry sqlite3_rtree_geometry;

typedef struct sqlite3_rtree_query_info sqlite3_rtree_query_info;

typedef double sqlite3_rtree_dbl;

int sqlite3_rtree_geometry_callback( 
    sqlite3 *db,
    const unsigned char *zGeom,
    int ( *xGeom )( 
        sqlite3_rtree_geometry *__MIDL____MIDL_itf_sqlite3_0000_00000602,
        int __MIDL____MIDL_itf_sqlite3_0000_00000603,
        sqlite3_rtree_dbl *__MIDL____MIDL_itf_sqlite3_0000_00000604,
        int *__MIDL____MIDL_itf_sqlite3_0000_00000605),
    void *pContext);

struct sqlite3_rtree_geometry
    {
    void *pContext;
    int nParam;
    sqlite3_rtree_dbl *aParam;
    void *pUser;
    void ( *xDelUser )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000607);
    } ;
int sqlite3_rtree_query_callback( 
    sqlite3 *db,
    const unsigned char *zQueryFunc,
    int ( *xQueryFunc )( 
        sqlite3_rtree_query_info *__MIDL____MIDL_itf_sqlite3_0000_00000609),
    void *pContext,
    void ( *xDestructor )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000611));

struct sqlite3_rtree_query_info
    {
    void *pContext;
    int nParam;
    sqlite3_rtree_dbl *aParam;
    void *pUser;
    void ( *xDelUser )( 
        void *__MIDL____MIDL_itf_sqlite3_0000_00000613);
    sqlite3_rtree_dbl *aCoord;
    unsigned int *anQueue;
    int nCoord;
    int iLevel;
    int mxLevel;
    sqlite3_int64 iRowid;
    sqlite3_rtree_dbl rParentScore;
    int eParentWithin;
    int eWithin;
    sqlite3_rtree_dbl rScore;
    } ;


extern RPC_IF_HANDLE __MIDL_itf_sqlite3_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sqlite3_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



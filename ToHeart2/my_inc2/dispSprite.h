#ifndef _DISP_SPRITE_H
#define _DISP_SPRITE_H

#include "disp.h"

#define PARTS_MAX		64
#define CHIP_MAX		128
#define SPRITE_MAX		256

#define ANIME_MAX			256
#define ANIME_CONTROL_MAX	256

#define BMP_FILE_MAX	32

typedef struct{
	WORD	code;	
	WORD	data1;	
	WORD	data2;	
	WORD	data3;	
}SPRITE_OPR;

typedef struct{
	BYTE	flag;	
	BYTE	r,g,b;	
	BYTE	bno;	
	WORD	dparam;	
	BYTE	param1;	
	BYTE	param2;	

	DWORD	rparam;	
	BYTE	zflag;	
	short	zoom;	
	long	nuki;	

	short	px,py;	
	short	sx,sy;	
	short	cx,cy;	
	long	group;
}PARTS_STRUCT;

typedef struct{
	char			flag;	
	char			r,g,b;	
	WORD			dparam;	
	char			param1;	
	char			param2;	

	DWORD			rparam;	
	char			zflag;	
	short			zoom;	

	long			group;	

	long			ps_max;	
	PARTS_STRUCT	*ps;	
}CHIP_STRUCT;

typedef struct{
	char			flag;		

	long			code_max;	
	SPRITE_OPR		*code;		
}SPRITE_STRUCT;



typedef struct{
	char			flag;		
	long			frame;		

	long			cs_max;		
	long			ss_max;		
	long			bmp_max;	

	CHIP_STRUCT		*cs;	
	SPRITE_STRUCT	*ss;
	char			*fname[BMP_FILE_MAX];	

	short			code2bno[BMP_FILE_MAX];	
}ANIME_STRUCT;

typedef struct{
	char			flag;		

	char			ano;		
	long			sp_no;		

	char			loop_no;	
	char			lcount[16];	

	long			count;		
	long			code_no;	
	long			draw_count;	

	char			through;
	char			rep_wait;
	short			event;


	long			next_code;	
	long			cfade;		

	long			mode;		

	long			end;		
	long			lnum;		
	long			speed;		

	RECT			draw_rect;	
}ANIME_CONTROL;










#define REPEAT_NULL		0
#define REPEAT_WAIT		1
#define REPEAT_FIND		2

#define SP_STOP		0
#define SP_PLAY		1

#define INF_LOOP	0

typedef struct{
	int		dx, dy;
	int		r,g,b;
	RECT	*clip;
	int		param;
	int		rparam;
	int		zoom;
}SPRITE_PARAM;

typedef struct{
	char			flag;	
	char			r,g,b;	
	WORD			dparam;	
	char			param1;	
	char			param2;	

	DWORD			rparam;	
	char			zflag;	
	short			zoom;	

	long			group;	

	long			ps_max;			
}CHIP_STRUCT2;

typedef struct{
	char			flag;		
	long			code_max;	
}SPRITE_STRUCT2;

typedef struct{
	char			flag;		
	long			frame;		

	long			cs_max;		
	long			ss_max;		
	long			bmp_max;	
}ANIME_STRUCT2;

typedef struct{
	DWORD	header;	
	DWORD	size;	
	short	ver_no;	
	short	resarve1;
	short	resarve2;
	short	resarve3;
}SPANI_HEADER;



#define SPCODE_NULL		0
#define SPCODE_DRAW		1
#define SPCODE_LOOP		2
#define SPCODE_REPEAT	3


extern void SPR_SetAntiFlag( int flag );

extern void SPR_RenewSprite( int frame, int interless );
extern void SPR_DrawSprite( void *dest, int draw_mode, int sp_no, int dx, int dy, int r, int g, int b, RECT *clip, int param, int rparam, int zoom );

extern BOOL SPR_CopySprite( int ani_no1,  int ani_no2, char *tfname=NULL, int viv=256, int r=128, int g=128, int b=128 );

extern BOOL SPR_LoadSprite( int ani_no, char *fname, char *tfname=NULL, int viv=256 );
extern BOOL SPR_LoadBmpSprite( int ani_no, char *fname, int nuki, char *tfname=NULL, int viv=256 );
extern BOOL SPR_ReleaseSprite( int ani_no );
extern void SPR_ReleaseSpriteAll( void );

extern BOOL SPR_SetSprite( int ani_no, int sp_no, int mode, int end, int lnum, int cfade );
extern BOOL SPR_ResetSprite( int ac_no );

extern BOOL SPR_SetSpriteSpeed( int ani_no, int speed );

extern BOOL SPR_SetSpritePlay( int ac_no, int ani_no, int sp_no, int mode, int end, int lnum, int cfade );
extern BOOL SPR_SetSpriteNo( int ac_no, int sp_no );
extern BOOL SPR_SetSpriteCfade( int ac_no, int flag );
extern BOOL SPR_SetSpriteLoop( int ac_no, int end, int lnum );
extern BOOL SPR_SetSpriteLoopThrough( int ac_no );

extern int  SPR_GetSpriteRepeatFind( int ac_no );
extern BOOL SPR_SetSpriteRepeatFind( int ac_no );

extern RECT *SPR_GetSpriteRect( int ac_no );

extern BOOL SPR_WaitSpriteCondition( int ac_no );

extern int  SPR_GetSpriteMode( int ac_no );
extern BOOL SPR_SetSpriteMode( int ac_no, int mode );

extern int SPR_GetSpriteEvent( int ac_no );

#endif 


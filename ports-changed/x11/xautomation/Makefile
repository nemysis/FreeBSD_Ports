# Created by: ijliao
# $FreeBSD: head/x11/xautomation/Makefile 307384 2012-11-13 16:28:06Z bdrewery $

PORTNAME=	xautomation
PORTVERSION=	1.07
CATEGORIES=	x11
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Control X from the command line for scripts

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_XORG=	xtst
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/pat2ppm bin/patextract bin/png2pat bin/rgb2pat \
		bin/visgrep bin/xmousepos bin/xte

MAN1=		pat2ppm.1 patextract.1 png2pat.1 rgb2pat.1 \
		visgrep.1 xmousepos.1 xte.1
MAN7=		xautomation.7

.include <bsd.port.mk>

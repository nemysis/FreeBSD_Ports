# Created by: ijliao
# $FreeBSD: head/games/vamos/Makefile 302037 2012-08-04 22:52:02Z kwm $

PORTNAME=	vamos
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF \
		http://${PORTNAME}.sourceforge.net/images/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		logo.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Automotive simulation framework

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_OPENAL=	al alut
USE_XORG=	sm ice x11 xi xext xmu
USE_GL=		glut
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	ac_cv_header_boost_test_unit_test_hpp=no \
		ac_cv_lib_freeglut_glutGetModifiers=no
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

# Wrong versioning upstream
PORTSCOUT=	skipv:0.7.1

INFO=		vamos

PORTDOCS=	AUTHORS ChangeLog README TODO

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DESKTOP_ENTRIES="Vamos" "${COMMENT}" \
		share/pixmaps/${PORTNAME}.png \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/config/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^AM_CXXFLAGS/s| -pedantic|| ; \
		 /^AM_CXXFLAGS/s| -O[[:alnum:]]|| ; \
		 /^AM_CXXFLAGS/s| -g|| ; \
		 /^AM_CXXFLAGS/s| -DBOOST_TEST_DYN_LINK|| ; \
		 /^AM_CXXFLAGS/s| -L/usr/lib/boost||'

post-install:
	${INSTALL_DATA} ${_DISTDIR}/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

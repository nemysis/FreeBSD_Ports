# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	allegro
DISTVERSION=	5.0.9
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform library for games and multimedia programming

LICENSE=	ZLIB

LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		physfs:${PORTSDIR}/devel/physfs
# Disabled because install allegro-devel-4*  and then is conflict, but is needed
#BUILD_DEPENDS+=	${LOCALBASE}/include/dumb.h:${PORTSDIR}/audio/dumb-allegro

USE_GMAKE=	yes
USES=		cmake pkgconfig
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_LDCONFIG=	yes
WANT_GNOME=	yes
USE_OPENAL=	soft
USE_GL=		gl glu
USE_FREETYPE=	yes

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	allegro-devel-4*
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

SHLIB_VER=	5.0.9

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

OPTIONS_DEFINE=	PULSEAUDIO

.include <bsd.port.options.mk>
.include "Makefile.man"

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${LOCALBASE}/bin/pandoc:${PORTSDIR}/textproc/hs-pandoc
.endif

PORTDOCS=	*
PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/allegro

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt
DOCSRCDIR2=	${WRKSRC}/docs

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/addons/audio/pulseaudio.c

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/man/* ${MAN3PREFIX}/man/man3

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@(cd ${DOCSRCDIR2} && ${COPYTREE_SHARE} "html src" ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

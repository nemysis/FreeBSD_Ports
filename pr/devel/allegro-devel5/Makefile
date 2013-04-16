# Created by:	nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	allegro
DISTVERSION=	5.0.7
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
PKGNAMESUFFIX=	-devel5

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform library for games and multimedia programming

LICENSE=	BSD

LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:${PORTSDIR}/textproc/hs-pandoc

USE_GL=		gl glu
USE_FREETYPE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
WANT_GNOME=	yes
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_GMAKE=	yes
USE_CMAKE=	yes
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

CONFLICTS=	allegro-[0-9]*
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}"

SHLIB_VER=	5.0.7

PORTSCOUT=	limit:^4\.3\.[0-9]*

PORTDOCS=	*
DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGES-5.0.txt CONTRIBUTORS.txt README.txt README_packaging.txt README_pkgconfig.txt

OPTIONS_DEFINE=	VORBIS FLAC OPENAL PHYSFS DEMOS
OPTIONS_DEFAULT=VORBIS FLAC OPENAL PHYSFS
PHYSFS_DESC=	Support for PhysicsFS
DEMOS_DESC=	Install Demos programs

.include <bsd.port.options.mk>
.include "Makefile.man"

.if ${PORT_OPTIONS:MDEMOS}
CMAKE_ARGS+=	-DWANT_DEMO=on
PLIST_SUB+=	DEMOS=""
.else
CMAKE_ARGS+=-DWANT_TESTS=off
.endif

.if ${PORT_OPTIONS:MVORBIS}
CMAKE_ARGS+=	-DWANT_VORBIS=ON
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg
.else
CMAKE_ARGS+=	-DWANT_VORBIS=OFF
.endif

.if ${PORT_OPTIONS:MFLAC}
CMAKE_ARGS+=	-DWANT_FLAC=ON
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
CMAKE_ARGS+=	-DWANT_FLAC=OFF
.endif

.if ${PORT_OPTIONS:MOPENAL}
CMAKE_ARGS+=	-DWANT_OPENAL=ON
USE_OPENAL=	soft
.else
CMAKE_ARGS+=	-DWANT_OPENAL=OFF
.endif

.if ${PORT_OPTIONS:MPHYSFS}
CMAKE_ARGS+=	-DWANT_PHYSFS=ON
LIB_DEPENDS+=	physfs:${PORTSDIR}/devel/physfs
.else
CMAKE_ARGS+=	-DWANT_PHYSFS=OFF
.endif

.if defined(WITH_PHYSFS)
PLIST_SUB+=	PHYSFS=""
.else
PLIST_SUB+=	PHYSFS="@comment "
.endif

.if defined(WITH_DEMOS)
PLIST_SUB+=	DEMOS=""
.else
PLIST_SUB+=	DEMOS="@comment "
.endif

post-install:
	@${CP} -p ${WRKSRC}/allegro5.cfg ${PREFIX}/etc/allegro5.cfg.sample

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MDEMOS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MMANPAGES}
	@cd ${WRKSRC}/docs/man/ && \
		${FIND} . -type f -and -name "*.3" -exec ${INSTALL_MAN} {} ${PREFIX}/man/man3/{} \;
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "src html" ${DOCSDIR})
.endif

.include <bsd.port.mk>

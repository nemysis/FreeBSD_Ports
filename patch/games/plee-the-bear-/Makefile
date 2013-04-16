# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD: head/games/plee-the-bear/Makefile 314960 2013-03-22 20:06:14Z makc $

PORTNAME=	plee-the-bear
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Plee%20the%20Bear/${PORTVERSION:R}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D platform jump and run game

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/CCPL
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost-libs \
		claw_application:${PORTSDIR}/devel/libclaw

USE_SDL=	sdl mixer
USE_GL=		gl glu
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.6+

USES=		cmake
CMAKE_ARGS=	-Dlibclaw_DIR="${LOCALBASE}/share/libclaw/cmake" \
		-DBEAR_NO_EDITOR=YES -DBEAR_NO_MANPAGES=YES

MAN6=		plee-the-bear.6 running-bear.6

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
#@${REINPLACE_CMD} -e 's|share/man/man|man/man|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' '/FILES $${_man_file}/,/DESTINATION share\/man\/man$${_volume}/s/^/#/' \
		${WRKSRC}/CMakeLists.txt

#	@${REINPLACE_CMD} -e 's|man||' \
#		${WRKSRC}/bear-engine/desktop/CMakeLists.txt \
#		${WRKSRC}/plee-the-bear/desktop/CMakeLists.txt

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|locale||' \
		${WRKSRC}/bear-engine/desktop/CMakeLists.txt \
		${WRKSRC}/plee-the-bear/desktop/CMakeLists.txt
#	@${REINPLACE_CMD} -i '' '/subdirs/d' ${WRKSRC}/plee-the-bear/desktop/CMakeLists.txt
#	${RM} -f ${WRKSRC}/bear-engine/desktop/CMakeLists.txt
#		${WRKSRC}/plee-the-bear/desktop/CMakeLists.txt
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/bear-engine/desktop/man/running-bear.6 ${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/plee-the-bear/desktop/man/plee-the-bear.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>

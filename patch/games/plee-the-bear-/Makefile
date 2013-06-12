# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD: head/games/plee-the-bear/Makefile 316407 2013-04-24 07:35:40Z ak $

PORTNAME=	plee-the-bear
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Plee%20the%20Bear/${PORTVERSION:R}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D platform jump and run game

LICENSE=	GPLv2 CCbySA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbySA3=Attribution-ShareAlike 3.0 Unported
LICENSE_FILE_CCbySA3=${WRKSRC}/CCPL
LICENSE_PERMS_CCbySA3=dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man
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
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|locale||' \
		${WRKSRC}/bear-engine/desktop/CMakeLists.txt \
		${WRKSRC}/plee-the-bear/desktop/CMakeLists.txt
.endif

post-build:
	@(cd ${WRKSRC}/bear-engine/desktop/man && docbook-to-man running-bear.sgml > running-bear.6)
	@(cd ${WRKSRC}/plee-the-bear/desktop/man && docbook-to-man plee-the-bear.sgml > plee-the-bear.6)

post-install:
	${INSTALL_MAN} ${WRKSRC}/bear-engine/desktop/man/running-bear.6 ${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/plee-the-bear/desktop/man/plee-the-bear.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>

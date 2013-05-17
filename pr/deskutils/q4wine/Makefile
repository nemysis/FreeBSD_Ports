# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD: head/deskutils/q4wine/Makefile 315248 2013-03-25 21:47:11Z jgh $

PORTNAME=	q4wine
PORTVERSION=	1.0.r3
CATEGORIES=	deskutils emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20$${PORTVERSION:S/.r/-r/}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	QT4 front-end for WINE

LICENSE=	GPLv3

BUILD_DEPENDS=	icotool:${PORTSDIR}/graphics/icoutils
RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo \
		wget:${PORTSDIR}/ftp/wget \
		cabextract:${PORTSDIR}/archivers/cabextract \
		icotool:${PORTSDIR}/graphics/icoutils

USES=		cmake desktop-file-utils
CMAKE_ARGS+=	-DMANPAGE_ENTRY_PATH=${MANPREFIX}/man
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	qmake_build rcc_build moc_build uic_build \
		linguist_build corelib gui sql network
ONLY_FOR_ARCHS=	i386 amd64

MAN1=		q4wine-cli.1 q4wine-helper.1 q4wine.1

OPTIONS_DEFINE=	NLS DBUS
OPTIONS_DEFAULT=	DBUS

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:${PORTSDIR}/emulators/wine-devel
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
.else
CMAKE_ARGS+=	-DWITH_DBUS:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^Categories=.*|Categories=Qt;System;Emulator;Utility;Game;|' \
		${WRKSRC}/${PORTNAME}.desktop

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|install(FILES|#install(FILES|' ${WRKSRC}/src/i18n/CMakeLists.txt
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>

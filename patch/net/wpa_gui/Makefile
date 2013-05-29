# Created by: Ilya Bakulin <webmaster@kibab.com>
# $FreeBSD: head/net/wpa_gui/Makefile 312761 2013-02-22 10:58:15Z makc $

PORTNAME=	wpa_gui
PORTVERSION=	2.0
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/
DISTNAME=	wpa_supplicant-${PORTVERSION}

MAINTAINER=	webmaster@kibab.com
COMMENT=	Qt-based frontend for wpa_supplicant

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${DISTNAME}/wpa_supplicant/wpa_gui-qt4

USE_QT4=	qmake_build moc_build uic_build \
		corelib gui network rcc
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	sbin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop
PLIST_DIRSTRY=	share/applications

MAN8=	${PORTNAME}.8

PORTDOCS=	ChangeLog README todo.txt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^Categories=.*|Categories=Qt;Network;System;|' \
		${WRKSRC}/${PORTNAME}.desktop

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/wpa_supplicant/doc/docbook/${MAN8} ${MAN8PREFIX}/man/man8

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/${DISTNAME}/wpa_supplicant/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

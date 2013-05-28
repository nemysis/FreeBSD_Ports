# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD: head/security/secpanel/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	secpanel
PORTVERSION=	0.6.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security tcl tk
MASTER_SITES=	SF/${PORTNAME} \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	GUI for managing and running ssh and related utilities

LICENSE=	GPLv2

RUN_DEPENDS=	ssh-askpass:${PORTSDIR}/security/openssh-askpass

WRKSRC=		${WRKDIR}/usr/local
NO_BUILD=	yes

USE_TK_WRAPPER=	yes

DESKTOP_ENTRIES="SecPanel" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Network;Security;" false

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\[file dirname \[info script\]\]/../lib/secpanel|${DATADIR}|' \
			${WRKSRC}/bin/secpanel

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/secpanel ${PREFIX}/bin
	@(cd ${WRKSRC}/lib/secpanel && ${COPYTREE_SHARE} . ${DATADIR})
	@${CHMOD} u+rw ${DATADIR}/default.config

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>

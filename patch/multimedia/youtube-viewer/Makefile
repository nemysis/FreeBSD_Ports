# New ports collection makefile for:	youtube-viewer
# Date created:		2010-08-17
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD: head/multimedia/youtube-viewer/Makefile 302651 2012-08-16 17:34:43Z dhn $
#

PORTNAME=	youtube
PORTVERSION=	3.0.2
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn
PKGNAMESUFFIX=	-viewer
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Search and play YouTube videos streaming in MPlayer

LICENSE=	GPLv3

RUN_DEPENDS=	p5-XML-Fast>=0:${PORTSDIR}/net/p5-XML-Fast \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-Data-Dump>=1.06:${PORTSDIR}/devel/p5-Data-Dump \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-Term-ReadKey>=2.10:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		mplayer:${PORTSDIR}/multimedia/mplayer

WRKSRC=	${WRKDIR}/WWW-YoutubeViewer
PROJECTHOST=	trizen
USE_PERL5_RUN=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/perl|#!${PERL}|g" ${WRKSRC}/bin/youtube-viewer

do-install:
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/WWW
	${INSTALL_DATA} ${WRKSRC}/lib/WWW/YoutubeViewer.pm ${PREFIX}/${SITE_PERL_REL}/WWW/
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/youtube-viewer ${PREFIX}/bin/

.include <bsd.port.mk>

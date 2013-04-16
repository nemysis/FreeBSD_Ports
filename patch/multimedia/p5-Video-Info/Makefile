# Ports collection makefile for:	p5-Video-Info
# Date Created:				Feb 25, 2004
# Whom:					ijliao
#
# $FreeBSD: ports/multimedia/p5-Video-Info/Makefile,v 1.11 2012/04/09 23:51:39 bapt Exp $
#

PORTNAME=	Video-Info
PORTVERSION=	0.993
PORTEPOCH=	1
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
MASTER_SITE_SUBDIR=	CPAN:ALLENDAY

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve video properties such as: height width codec fps

BUILD_DEPENDS=	p5-Video-OpenQuicktime>=0:${PORTSDIR}/multimedia/p5-Video-OpenQuicktime \
		devel/p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		audio/p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info

PERL_CONFIGURE=	yes
PERL_CONFIGURE=	yes
MANCOMPRESSED=	no

MAN3=		Video::Info.3 Video::Info::MPEG::Constants.3 Video::Info::RIFF.3 \
		Video::Info::MPEG::Audio.3 Video::Info::MPEG::System.3 Video::Info::Magic.3 \
		Video::Info::FOO.3 Video::Info::MPEG.3 Video::Info::ASF.3 Video::Info::Quicktime.3 \
		Video::Info::MPEG::Video.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500803
	${PERL} -pi -e '$$_="" if m{5.008|warnings}' ${WRKSRC}/Makefile.PL ${WRKSRC}/lib/Video/Info.pm
.endif

.include <bsd.port.post.mk>

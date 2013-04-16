# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD: head/graphics/l2p/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	l2p
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	graphics print perl5
MASTER_SITES=	http://static.redsymbol.net/software/l2p/dist/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Create PNG images from LaTeX math expressions

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX

USE_PERL5_RUN=	yes
USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/l2p
PORTDOCS=	l2p.txt l2p.html

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL} -w|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

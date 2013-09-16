# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook2odf
PORTVERSION=	0.244
CATEGORIES=	textproc perl5
MASTER_SITES=	http://open.comsultia.com/docbook2odf/dwn/
PKGNAMEPREFIX=	p5-

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Convert docbook document to Oasis Open Document

LICENSE=	GPLv2

LIB_DEPENDS=	sablot:${PORTSDIR}/textproc/sablotron \
		xslt:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		zip:${PORTSDIR}/archivers/zip \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip

USES=		desktop-file-utils
USE_PERL5=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTEXAMPLES=	*

MAN1=		${PORTNAME}.1

.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name .cvsignore -type f -print0 | \
		${XARGS} -0 ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e 's|#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/tests/tests/docbook-43.001.xml ${WRKSRC}/utils/maketests \
		${WRKSRC}/utils/${PORTNAME}
	@${RM} ${WRKSRC}/tests/tests/*.bak
	@(cd ${WRKSRC}/utils && ${RM} *.bak)

do-install:
	${LN} -sf ${DATADIR}/utils/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "tests utils xsl" ${DATADIR})
	@(cd ${DATADIR}/utils && ${CHMOD} 555 *)
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/bindings/desktop/${PORTNAME}.desktop ${PREFIX}/share/applications
	${LN} -sf ${EXAMPLESDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>

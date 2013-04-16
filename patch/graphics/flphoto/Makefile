# Created by: johan
# $FreeBSD: head/graphics/flphoto/Makefile 309385 2012-12-22 11:51:49Z mandree $

PORTNAME=	flphoto
PORTVERSION=	1.3.1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/fltk/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic image management and display program

LICENSE=	GPLv2

LIB_DEPENDS=	gphoto2:${PORTSDIR}/graphics/libgphoto2 \
		fltk:${PORTSDIR}/x11-toolkits/fltk \
		png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_XORG=	xinerama
GNU_CONFIGURE=	yes

MAN1=		flphoto.1
MAN5=		album.5

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	ANNOUNCEMENT CHANGES README

DOCSRCDIR2=	${WRKSRC}/doc
DOC_FILES2=	*.jpg *.html *.png

DESKTOP_ENTRIES="flPhoto" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;" false

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@OPTIM@|-DHAVE_CONFIG_H|g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flphoto ${PREFIX}/bin/flphoto
	${INSTALL_MAN} ${WRKSRC}/doc/flphoto.man ${MAN1PREFIX}/man/man1/flphoto.1
	${INSTALL_MAN} ${WRKSRC}/doc/album.man ${MAN5PREFIX}/man/man5/album.5

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR}
.endif
	${LN} -sf ${DOCSDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MNLS}
. for lang in de en_CA en_GB es fr it nl pt
	@${MKDIR} ${PREFIX}/share/locale/${lang}
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.po \
		${PREFIX}/share/locale/${lang}/flphoto_${lang}
. endfor
.endif
.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc
.endif

.include <bsd.port.post.mk>

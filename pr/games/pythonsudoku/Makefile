# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pythonsudoku
PORTVERSION=	0.13
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/Python%20Sudoku/${PORTVERSION}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Text and graphical program to create or resolve Sudokus

LICENSE=	GPLv2

LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-client
RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}reportlab>=0:${PORTSDIR}/print/py-reportlab

USE_BZIP2=	yes
USES=		desktop-file-utils
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

MAN6=		pysdk-gui.6 pysdk-image.6 pysdk-pdf.6 pysdk.6

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	Changelog README TODO

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.png *.html *.txt *.css

DESKTOP_ENTRIES="Python Sudoku" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/games|${PREFIX}/bin|' \
		-e 's|/usr/share/games|${PREFIX}/share|' \
		${WRKSRC}/setup.cfg
	@${REINPLACE_CMD} -e 's|#localedir = "DIRECTORY"|localedir = "${PREFIX}/share/locale"|' \
		${WRKSRC}/pythonsudoku/config.py

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' '/for lingua in linguas():/,/\["locale\/%s\/LC_MESSAGES\/pythonsudoku.mo" % lingua\]))/s/^/#/' \
		${WRKSRC}/setup.py
.endif

post-install:
	@cd ${PREFIX}/bin && ${LN} -sf pysdk-gui.py ${PORTNAME}
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.6 ${MAN6PREFIX}/man/man6
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>

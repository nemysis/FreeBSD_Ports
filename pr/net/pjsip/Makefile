# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pjsip
PORTVERSION=	2.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.pjsip.org/release/${PORTVERSION}/
DISTNAME=	pjproject-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	The portable and versatile SIP stack

LICENSE=	GPLv2

LIB_DEPENDS+=	portaudio:${PORTSDIR}/audio/portaudio

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BZIP2=	yes

USE_DOS2UNIX=	*.cfg
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}

SUB_FILES=	pkg-install \
		pkg-message

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt

DOCSRCDIR_PJLIB_HTML=		${WRKSRC}/pjlib/docs/html
DOCSDIR_PJLIB_HTML=		${DOCSDIR}/pjlib/docs/html
DOC_FILES_PJLIB_HTML=		*.htm *.css *.js *.png

DOCSRCDIR_PJLIB_LATEX=		${WRKSRC}/pjlib/docs/latex
DOCSDIR_PJLIB_LATEX=		${DOCSDIR}/pjlib/docs/latex
DOC_FILES_PJLIB_LATEX=		Makefile *.tex *.sty

DOCSRCDIR_PJLIB_UTIL_HTML=	${WRKSRC}/pjlib-util/docs/html
DOCSDIR_PJLIB_UTIL_HTML=	${DOCSDIR}/pjlib-util/docs/html
DOC_FILES_PJLIB_UTIL_HTML=	*.htm *.css *.js *.png

DOCSRCDIR_PJLIB_UTIL_LATEX=	${WRKSRC}/pjlib-util/docs/latex
DOCSDIR_PJLIB_UTIL_LATEX=	${DOCSDIR}/pjlib-util/docs/latex
DOC_FILES_PJLIB_UTIL_LATEX=	Makefile *.tex *.sty

DOCSRCDIR_PJMEDIA_HTML=		${WRKSRC}/pjmedia/docs/html
DOCSDIR_PJMEDIA_HTML=		${DOCSDIR}/pjmedia/docs/html
DOC_FILES_PJMEDIA_HTML=		*.htm *.css *.js *.png

DOCSRCDIR_PJMEDIA_LATEX=	${WRKSRC}/pjmedia/docs/latex
DOCSDIR_PJMEDIA_LATEX=		${DOCSDIR}/pjmedia/docs/latex
DOC_FILES_PJMEDIA_LATEX=	Makefile *.tex *.sty

DOCSRCDIR_PJNATH_HTML=		${WRKSRC}/pjnath/docs/html
DOCSDIR_PJNATH_HTML=		${DOCSDIR}/pjnath/docs/html
DOC_FILES_PJNATH_HTML=		*.htm *.css *.js *.png

DOCSRCDIR_PJNATH_LATEX=		${WRKSRC}/pjnath/docs/latex
DOCSDIR_PJNATH_LATEX=		${DOCSDIR}/pjnath/docs/latex
DOC_FILES_PJNATH_LATEX=		Makefile *.tex *.sty

DOCSRCDIR_PJSIP_HTML=		${WRKSRC}/pjsip/docs/html
DOCSDIR_PJSIP_HTML=		${DOCSDIR}/pjsip/docs/html
DOC_FILES_PJSIP_HTML=		*.htm *.css *.js *.png

DOCSRCDIR_PJSIP_LATEX=		${WRKSRC}/pjsip/docs/latex
DOCSDIR_PJSIP_LATEX=		${DOCSDIR}/pjsip/docs/latex
DOC_FILES_PJSIP_LATEX=		Makefile *.tex *.sty

OPTIONS_DEFINE=	SSL SOUND OSS V4L FFMPEG SPEEX GSM ILBC G711 G722 G7221 L16 SDL SAMPLERATE OPENCORE DOXYGEN HTML LATEX

OPTIONS_SINGLE=		PAPER
OPTIONS_SINGLE_PAPER=	A4 A4WIDE LETTER LEGAL EXECUTIVE

OPTIONS_DEFAULT=SSL SOUND OSS V4L FFMPEG SPEEX GSM ILBC G711 G722 G7221 L16 SDL A4

V4L_DESC=	Video4Linux2 support
ILBC_DESC=	iLBC audio codec
G711_DESC=	G.711 audio codec
G722_DESC=	G.722 audio codec
G7221_DESC=	G.722.1 audio codec
L16_DESC=	Linear/L16 audio codec
OPENCORE_DESC=	OpenCORE Adaptive Multi Rate
HTML_DESC=	Install HTML Doxygen files
LATEX_DESC=	Install LaTeX Doxygen files
A4_DESC=	Use paper type A4
A4WIDE_DESC=	Use paper type A4wide
LETTER_DESC=	Use paper type Letter
LEGAL_DESC=	Use paper type Legal
EXECUTIVE_DESC=	Use paper type Executive

.include <bsd.port.options.mk>
.include "${.CURDIR}/Makefile.depends"

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=--enable-ssl
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

.if ${PORT_OPTIONS:MSOUND}
CONFIGURE_ARGS+=--enable-sound
.else
CONFIGURE_ARGS+=--disable-sound
.endif

.if ${PORT_OPTIONS:MOSS}
CONFIGURE_ARGS+=--enable-oss
.else
CONFIGURE_ARGS+=--disable-oss
.endif

.if ${PORT_OPTIONS:MV4L}
CONFIGURE_ARGS+=--enable-v4l2 --enable-video
.else
CONFIGURE_ARGS+=--disable-v4l2 --disable-video
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CONFIGURE_ARGS+=--enable-ffmpeg
.else
CONFIGURE_ARGS+=--disable-ffmpeg
.endif

.if ${PORT_OPTIONS:MSPEEX}
CONFIGURE_ARGS+=--enable-speex-codec --enable-speex-aec
.else
CONFIGURE_ARGS+=--disable-speex-codec --disable-speex-aec
.endif

.if ${PORT_OPTIONS:MGSM}
CONFIGURE_ARGS+=--enable-gsm-codec
.else
CONFIGURE_ARGS+=--disable-gsm-codec
.endif

.if ${PORT_OPTIONS:MILBC}
CONFIGURE_ARGS+=--enable-ilbc-codec
.else
CONFIGURE_ARGS+=--disable-ilbc-codec
.endif

.if ${PORT_OPTIONS:MG711}
CONFIGURE_ARGS+=--enable-g711-codec
.else
CONFIGURE_ARGS+=--disable-g711-codec
.endif

.if ${PORT_OPTIONS:MG722}
CONFIGURE_ARGS+=--enable-g722-codec
.else
CONFIGURE_ARGS+=--disable-g722-codec
.endif

.if ${PORT_OPTIONS:MG7221}
CONFIGURE_ARGS+=--enable-g7221-codec
.else
CONFIGURE_ARGS+=--disable-g7221-codec
.endif

.if ${PORT_OPTIONS:ML16}
CONFIGURE_ARGS+=--enable-l16-codec
.else
CONFIGURE_ARGS+=--disable-l16-codec
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl image mixer
CONFIGURE_ARGS+=--enable-sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
CONFIGURE_ARGS+=--enable-libsamplerate
.else
CONFIGURE_ARGS+=--disable-libsamplerate
.endif

.if ${PORT_OPTIONS:MOPENCORE}
CONFIGURE_ARGS+=--enable-opencore-amrnb --with-opencore-amrnb=${PREFIX}/include/opencore-amrnb
.else
CONFIGURE_ARGS+=--disable-opencore-amrnb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/pkgconfig|/libdata/pkgconfig|g' \
		-e 's|$$(DESTDIR)$$(prefix)|$$(DESTDIR)${PREFIX}|g' \
		-e 's|$$(DESTDIR)/$$(prefix)|$$(DESTDIR)/${PREFIX}|g' \
		${WRKSRC}/Makefile

.if ${PORT_OPTIONS:MV4L}
	@${ECHO_CMD} "#define PJMEDIA_HAS_VIDEO"              1 >> ${WRKSRC}/pjlib/include/pj/config_site.h
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
	@${ECHO_CMD} "#define PJMEDIA_RESAMPLE_IMP              PJMEDIA_RESAMPLE_LIBRESAMPLE" >> ${WRKSRC}/pjlib/include/pj/config_site.h
.endif

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS})

do-build:
	cd ${WRKSRC} && ${GMAKE} all && ${GMAKE} clean && ${GMAKE}

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL}

.for b in pjsua-* pjsystest-*
	${INSTALL_PROGRAM} ${WRKSRC}/pjsip-apps/bin/${b} ${PREFIX}/bin
	cd ${PREFIX}/bin/ && ${LN} -sf pjsua-* pjsua
	cd ${PREFIX}/bin/ && ${LN} -sf pjsystest-* pjsystest
.endfor

	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/pjsip-apps/bin/samples/*/* ${DATADIR}

.for b in pjlib pjlib-util pjmedia pjnath pjsip
	${INSTALL_PROGRAM} ${WRKSRC}/${b}/bin/* ${PREFIX}/bin
	@(cd ${PREFIX}/bin/ && ${LN} -sf pjlib-test-* pjlib-test && \
	${LN} -sf pjlib-util-test-* pjlib-util-test && \
	${LN} -sf pjmedia-test-* pjmedia-test && \
	${LN} -sf pjnath-test-* pjnath-test && \
	${LN} -sf pjturn-client-* pjturn-client && \
	${LN} -sf pjturn-srv-* pjturn-srv && \
	${LN} -sf pjsip-test-* pjsip-test)
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MA4}
. for d in pjlib pjlib-util pjmedia pjnath pjsip
	@(${REINPLACE_CMD} -e 's|PAPER_TYPE             = a4wide|PAPER_TYPE             = a4|g' ${WRKSRC}/${d}/docs/doxygen.cfg)
. endfor
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MLETTER}
. for d in pjlib pjlib-util pjmedia pjnath pjsip
	@(${REINPLACE_CMD} -e 's|PAPER_TYPE             = a4wide|PAPER_TYPE             = letter|g' ${WRKSRC}/${d}/docs/doxygen.cfg)
. endfor
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MLEGAL}
. for d in pjlib pjlib-util pjmedia pjnath pjsip
	@(${REINPLACE_CMD} -e 's|PAPER_TYPE             = a4wide|PAPER_TYPE             = legal|g' ${WRKSRC}/${d}/docs/doxygen.cfg)
. endfor
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MEXECUTIVE}
. for d in pjlib pjlib-util pjmedia pjnath pjsip
	@(${REINPLACE_CMD} -e 's|PAPER_TYPE             = a4wide|PAPER_TYPE             = executive|g' ${WRKSRC}/${d}/docs/doxygen.cfg)
. endfor
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MHTML} | ${PORT_OPTIONS:MLATEX}
. for d in pjlib pjlib-util pjmedia pjnath pjsip
		@${REINPLACE_CMD} -e 's|GENERATE_LATEX         = NO|GENERATE_LATEX         = YES|' \
		-e 's|PDF_HYPERLINKS         = NO|PDF_HYPERLINKS         = YES|' \
		-e 's|USE_PDFLATEX           = NO|USE_PDFLATEX           = YES|' \
		${WRKSRC}/${d}/docs/doxygen.cfg
. endfor
. for d in pjlib pjlib-util pjmedia pjnath pjsip
	@cd ${WRKSRC}/${d} && doxygen docs/doxygen.cfg
. endfor
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MHTML}
	${MKDIR} ${DOCSDIR_PJLIB_HTML}
	${INSTALL_DATA} ${DOC_FILES_PJLIB_HTML:S|^|${DOCSRCDIR_PJLIB_HTML}/|} ${DOCSDIR_PJLIB_HTML}
	${MKDIR} ${DOCSDIR_PJLIB_UTIL_HTML}
	${INSTALL_DATA} ${DOC_FILES_PJLIB_UTIL_HTML:S|^|${DOCSRCDIR_PJLIB_UTIL_HTML}/|} ${DOCSDIR_PJLIB_UTIL_HTML}
	${MKDIR} ${DOCSDIR_PJMEDIA_HTML}
	${INSTALL_DATA} ${DOC_FILES_PJMEDIA_HTML:S|^|${DOCSRCDIR_PJMEDIA_HTML}/|} ${DOCSDIR_PJMEDIA_HTML}
	${MKDIR} ${DOCSDIR_PJNATH_HTML}
	${INSTALL_DATA} ${DOC_FILES_PJNATH_HTML:S|^|${DOCSRCDIR_PJNATH_HTML}/|} ${DOCSDIR_PJNATH_HTML}
	${MKDIR} ${DOCSDIR_PJSIP_HTML}
	${INSTALL_DATA} ${DOC_FILES_PJSIP_HTML:S|^|${DOCSRCDIR_PJSIP_HTML}/|} ${DOCSDIR_PJSIP_HTML}
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MLATEX}
	${MKDIR} ${DOCSDIR_PJLIB_LATEX}
	${INSTALL_DATA} ${DOC_FILES_PJLIB_LATEX:S|^|${DOCSRCDIR_PJLIB_LATEX}/|} ${DOCSDIR_PJLIB_LATEX}
	${MKDIR} ${DOCSDIR_PJLIB_UTIL_LATEX}
	${INSTALL_DATA} ${DOC_FILES_PJLIB_UTIL_LATEX:S|^|${DOCSRCDIR_PJLIB_UTIL_LATEX}/|} ${DOCSDIR_PJLIB_UTIL_LATEX}
	${MKDIR} ${DOCSDIR_PJMEDIA_LATEX}
	${INSTALL_DATA} ${DOC_FILES_PJMEDIA_LATEX:S|^|${DOCSRCDIR_PJMEDIA_LATEX}/|} ${DOCSDIR_PJMEDIA_LATEX}
	${MKDIR} ${DOCSDIR_PJNATH_LATEX}
	${INSTALL_DATA} ${DOC_FILES_PJNATH_LATEX:S|^|${DOCSRCDIR_PJNATH_LATEX}/|} ${DOCSDIR_PJNATH_LATEX}
	${MKDIR} ${DOCSDIR_PJSIP_LATEX}
	${INSTALL_DATA} ${DOC_FILES_PJSIP_LATEX:S|^|${DOCSRCDIR_PJSIP_LATEX}/|} ${DOCSDIR_PJSIP_LATEX}
.endif

# Dynamically generate part of the PLIST, because is used suffix -$(TARGET_NAME)
	@${FIND} ${PREFIX}/bin -name pjsua* -or -name pjsystest* -or -name pjlib-test* \
	-or -name pjlib-util-test* -or -name pjmedia-test* -or -name pjnath-test* \
	-or -name pjturn-client* -or -name pjturn-srv* -or -name pjsip-test* | \
		${SED} 's,^${PREFIX}/,,' | ${SORT} >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib -name libpj* -or -name libg7221codec* -or -name libmilenage* \
		-or -name libgsmcodec* -or -name libilbccodec* -or -name libportaudio-*  \
		-or -name libresample-* -or -name libspeex-* -or -name libsrtp-* | \
		${SED} 's,^${PREFIX}/,,' | ${SORT} -r >> ${TMPPLIST}

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTAL

.include <bsd.port.mk>
